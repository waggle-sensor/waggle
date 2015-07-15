module IO.Runner(Request, Response, run) where

{-| Once you've constructed your IO computation `foo : IO ()`, you
can run it by adding the following to the file (Foo.elm) you're running:

port requests : Signal IO.Runner.Request
port requests = IO.Runner.run responses foo

port responses : Signal IO.Runner.Response

Then run `elm-make Foo.elm --output foo.js` to compile the program and
`elm-io.sh foo.js` to run it. You will need `node` installed to run
the program. Also you will need `npm install jsdom` in the directory
where you are running the file or globally. The `elm-io.sh` script can
be downloaded here:
https://raw.githubusercontent.com/maxsnew/IO/master/elm-io.sh

-}

import Dict
import Json.Decode exposing ((:=))
import Json.Decode as JSD
import Json.Encode as JSE
import List exposing ((::))
import List
import Result
import Signal exposing (Signal, (<~), foldp)
import String
import Trampoline
    
import IO.IO as IO
import IO.IO exposing (IO)

-- Internal Request representation
type IRequest = Put String
              | Exit Int
              | Get
              | WriteFile { file : String, content : String}
type alias IResponse = Maybe String


-- User-facing Request representation
type alias Request = JSD.Value
type alias Response = JSD.Value
type alias IOState  = { buffer : String }

start : IOState 
start = { buffer = "" }

run : Signal Response -> IO () -> Signal Request
run resps io = 
  let init               = (\_ -> io, start, [])
      f resp (io, st, _) = step (deserialize resp) io st
      third (_, _, z)    = z
  in serialize << third <~ foldp f init resps

resDecoder : JSD.Decoder String
resDecoder = ("Just" := JSD.string)

deserialize : Response -> IResponse
deserialize resp = Result.toMaybe (JSD.decodeValue resDecoder resp)

serialize : List IRequest -> Request
serialize reqs =
  let serReq req = 
        case req of
          Put s -> JSE.object [ ("ctor", JSE.string "Put")
                              , ("val",  JSE.string s)
                         ]
          Get -> JSE.object [ ("ctor", JSE.string "Get") ]
          Exit n -> JSE.object [ ("ctor", JSE.string "Exit")
                               , ("val", JSE.int n )
                          ]
          WriteFile { file, content} -> JSE.object [ ("ctor", JSE.string "WriteFile")
                                                   , ("file", JSE.string file)
                                                   , ("content", JSE.string content)
                                                   ]
    in JSE.list (List.map serReq reqs)

putS : String -> IRequest
putS = Put

exit : Int -> IRequest
exit = Exit

getS : IRequest
getS = Get

writeF : { file : String, content : String } -> IRequest
writeF = WriteFile

-- | Extract all of the requests that can be run now
extractRequests : IO a -> State IOState (List IRequest, () -> IO a)
extractRequests io = 
  case io of
    IO.Pure x -> pure ([exit 0], \_ -> IO.Pure x)
    IO.Impure iof -> case iof of
      IO.PutS s k     -> mapSt (mapFst (\rs -> putS s :: rs)) <| pure ([], k)
      IO.WriteF obj k -> mapSt (mapFst (\rs -> writeF obj :: rs)) <| pure ([], k)
      IO.Exit n       -> pure ([exit n], \_ -> io)
      IO.GetC k       ->
        ask >>= \st ->
        case String.uncons st.buffer of
          Nothing -> pure ([getS], \_ -> io)
          Just (c, rest) ->
            put ({ buffer = rest }) >>= \_ ->
            extractRequests (k c)

flattenReqs : List IRequest -> List IRequest
flattenReqs rs =
  let loop rs acc n =
    if n >= 100
    then Trampoline.Continue (\_ -> loop rs acc 0)
    else 
      case rs of
        []  -> Trampoline.Done <| List.reverse acc
        [r] -> loop [] (r::acc) (n+1)
        r1 :: r2 :: rs' ->
        case (r1, r2) of
          (Exit n, _)      -> loop [] (r1::acc) (n+1)
          (Put s1, Put s2) -> loop (putS (s1++s2) :: rs') acc (n+1)
          _                -> loop (r2::rs') (r1::acc) (n+1)
    in Trampoline.trampoline <| loop rs [] 0
                         
-- | We send a batch job of requests, all requests until IO blocks
step : IResponse -> (() -> IO a) -> IOState -> (() -> IO a, IOState, List IRequest)
step resp io st = 
  let newST = case resp of 
        Nothing -> st
        Just s  -> { st | buffer <- String.append st.buffer s }
      (newST', (rs, k)) = extractRequests (io ()) newST
  in (k, newST', rs)

-- | State monad
type alias State s a = s -> (s, a)

pure : a -> State s a
pure x = \s -> (s, x)

mapSt : (a -> b) -> State s a -> State s b
mapSt f sf = sf >>= (pure << f)

(>>=) : State s a -> (a -> State s b) -> State s b
f >>= k = \s -> let (s', y) = f s
                in k y s'

ask : State s s
ask = \s -> (s, s)

put : s -> State s ()
put s = \_ -> (s, ())

mapFst : (a -> b) -> (a,c) -> (b,c)
mapFst f (x,y) = (f x, y)
