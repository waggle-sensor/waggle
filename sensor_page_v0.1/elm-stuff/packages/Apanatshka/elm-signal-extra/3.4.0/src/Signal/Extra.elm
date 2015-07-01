module Signal.Extra((~>),zip,zip3,zip4,unzip,unzip3,unzip4,foldp',foldps,foldps',runBuffer,runBuffer',delayRound,keepIf,keepWhen,sampleWhen,switchWhen,keepWhenI,switchSample,keepThen,filter,filterMap,filterFold,fairMerge,combine,mapMany,applyMany) where
{-| Utility functions that aren't in the `Signal` module from
`elm-lang/core`. 

# Flipped fancy map
@docs (~>)

# Zipping and unzipping
For those too lazy to write a record or union type.  
@docs zip, zip3, zip4, unzip, unzip3, unzip4

# Stateful
@docs foldp', foldps, foldps', runBuffer, runBuffer', delayRound

# Switching
@docs switchWhen,switchSample

# Filters
@docs keepIf,keepWhen,sampleWhen,keepThen,keepWhenI,filter,filterMap

# Combining
@docs fairMerge, combine, mapMany, applyMany
-}

import Signal exposing (map,map2,map3,map4,(<~),(~),sampleOn,constant,foldp,merge,dropRepeats)

{-| The `(<~)` operator, but flipped. Doesn't play well with the other
two!

    Mouse.x ~> toFloat >> sqrt >> round
            >> isEven >> not
            >> asText
-}
(~>) : Signal a -> (a -> b) -> Signal b
(~>) =
  flip map

infixl 4 ~>


{-| Zip two signals into a signal of pairs. 

    zip Mouse.x Mouse.y == Mouse.position
-}
zip : Signal a -> Signal b -> Signal (a,b)
zip =
  map2 (,)


{-| -}
zip3 : Signal a -> Signal b -> Signal c -> Signal (a,b,c)
zip3 =
  map3 (,,)


{-| -}
zip4 : Signal a -> Signal b -> Signal c -> Signal d -> Signal (a,b,c,d)
zip4 =
  map4 (,,,)


{-| Unzip a signal of pairs to a pair of signals. 

    unzip Mouse.position == (Mouse.x, Mouse.y)
-}
unzip : Signal (a,b) -> (Signal a, Signal b)
unzip pairS =
  (fst <~ pairS, snd <~ pairS)


{-| -}
unzip3 : Signal (a,b,c) -> (Signal a, Signal b, Signal c)
unzip3 pairS =
  ((\(a,_,_) -> a) <~ pairS, (\(_,b,_) -> b) <~ pairS, (\(_,_,c) -> c) <~ pairS)


{-| -}
unzip4 : Signal (a,b,c,d) -> (Signal a, Signal b, Signal c, Signal d)
unzip4 pairS =
  ((\(a,_,_,_) -> a) <~ pairS, (\(_,b,_,_) -> b) <~ pairS, (\(_,_,c,_) -> c) <~ pairS, (\(_,_,_,d) -> d) <~ pairS)


{-| Drops all updates to a signal, keeps only the initial value.
-}
initSignal : Signal a -> Signal a
initSignal s =
  sampleOn (constant ()) s


{-| `foldp'` is slighty more general than `foldp` in that you can base
the initial value of the state on the initial value of the input value. 

    foldp f b s == foldp' f (always b) s
-}
foldp' : (a -> b -> b) -> (a -> b) -> Signal a -> Signal b
foldp' fun initFun input =
  let -- initial has no events, only the initial value is used
    initial = initSignal input ~> initFun
    -- both the initial value and the normal input are given to fun'
    rest = foldp fun' Nothing (zip input initial)
    -- when mb is Nothing, input had its first event to use ini
    -- otherwise use the b from Just
    fun' (inp, ini) mb =
      Maybe.withDefault ini mb
      |> fun inp |> Just
    
    fromJust (Just a) = a
  in
    fromJust <~ merge (Just <~ initial) rest


{-| Like `foldp`, but with a hidden state

    foldp f b i ==
      let d a = (a,a) -- doubling function
      in foldps (\a b -> f a b |> d) (d b) i
-}
foldps : (a -> s -> (b,s)) -> (b,s) -> Signal a -> Signal b
foldps f bs aS =
  fst <~ foldp (\a (_,s) -> f a s) bs aS


{-| Like `foldp'`, but with a hidden state
-}
foldps' : (a -> s -> (b,s)) -> (a -> (b,s)) -> Signal a -> Signal b
foldps' f iF aS = fst <~ foldp' (\a (_,s) -> f a s) iF aS


{-| Not sure if this is useful for people, but it's a convenient building block:

    foldps == foldpWith id
    foldp f b ==
      let d a = (a,a)
      in foldpWith d f (d b)
-}
foldpWith : (h -> (b,s)) -> (a -> s -> h) -> (b,s) -> Signal a -> Signal b
foldpWith unpack step init input =
  let
    step' a (_,s) = -- : a -> (b,s) -> (b,s)
      step a s |> unpack
  in
    foldp step' init input ~> fst


{-| A running buffer of the given size (`n`) of the given signal. 
The list of at most `n` of the last values on the input signal. Starts
with an empty list. Adds new values to the *end* of the list! So you get
a list with time going from left to right. 

    ((==) [1,2,3,4,5]) <~ runBuffer 5 (count (Time.every second))
-}
runBuffer : Int -> Signal a -> Signal (List a)
runBuffer = runBuffer' []

{-| Same as `runBuffer` but with an initial buffer. 
-}
runBuffer' : List a -> Int -> Signal a -> Signal (List a)
runBuffer' l n input =
  let
    f inp prev =
      let
        l = List.length prev
      in
        if l < n
          then prev ++ [inp]
          else List.drop (l-n+1) prev ++ [inp]
  in
    foldp f l input


{-| Instead of delaying for some amount of time, delay for one round,
where a round is initiated by outside event to the Elm program.  
This may not be be very useful yet. Let the package author know if you
find a good use!  
Also known to `delay` in E-FRP. 
-}
delayRound : b -> Signal b -> Signal b
delayRound b bS =
  foldps (\new old -> (old, new)) (b,b) bS


{-| Switch between two signals. When the first signal is `True`, use the
 second signal, otherwise use the third. 
-}
switchWhen : Signal Bool -> Signal a -> Signal a -> Signal a
switchWhen b l r =
  switchHelper keepWhen b l r


{-| Same as the previous, but samples the signal it switches to. -}
switchSample : Signal Bool -> Signal a -> Signal a -> Signal a
switchSample b l r =
  switchHelper sampleWhen b l r


switchHelper : (Signal Bool -> Maybe a -> Signal (Maybe a) -> Signal (Maybe a))
             -> Signal Bool -> Signal a -> Signal a -> Signal a
switchHelper filter b l r =
  let
    base =
      (\bi li ri -> Just <| if bi then li else ri)
      <~ initSignal b
       ~ initSignal l
       ~ initSignal r
    
    lAndR =
      merge
        (filter b          Nothing (Just <~ l))
        (filter (not <~ b) Nothing (Just <~ r))
    
    fromJust (Just a) = a
  in
    fromJust <~ merge base lAndR

{-| The old name for `Signal.filter`, which doesn't confuse you with what the `Bool` value means. 
-}
keepIf : (a -> Bool) -> a -> Signal a -> Signal a
keepIf = Signal.filter

{-| The good old `keepWhen` filter that keeps events from the `Signal a` as long as the
`Signal Bool` is true. 
-}
keepWhen : Signal Bool -> a -> Signal a -> Signal a
keepWhen boolSig a aSig =
  zip boolSig aSig
  |> sampleOn aSig
  |> keepIf fst (True, a)
  |> map snd

{-| A combination of `Signal.sampleOn` and `keepWhen`. When the
first signal becomes `True`, the most recent value of the second signal
will be propagated.  
[Before Elm 0.12](
https://github.com/elm-lang/elm-compiler/blob/master/changelog.md#012)
 this was the standard behaviour of `keepWhen`.
-}
sampleWhen : Signal Bool -> a -> Signal a -> Signal a
sampleWhen bs def sig =
  zip bs sig
  |> keepIf fst (True, def)
  |> map snd


{-| Like `keepWhen`, but when the filter signal turn `False`, the output
changes back to the base value. 
-}
keepThen : Signal Bool -> a -> Signal a -> Signal a
keepThen choice base signal = 
  switchSample choice signal <| constant base
  
{-| `keepWhen` but always keeps the initial value rather than trying to
filter it. 
-}
keepWhenI : Signal Bool -> Signal a -> Signal a
keepWhenI fs s = 
  let
    fromJust (Just a) = a
  in
    keepWhen (merge (constant True) fs) Nothing (Just <~ s) ~> fromJust


{-| Filter a signal of optional values, discarding `Nothing`s.
-}
filter : a -> Signal (Maybe a) -> Signal a
filter initial =
  keepIf (\mx -> case mx of { Nothing -> False; _ -> True }) (Just initial)
  >> map (\mx -> let (Just x) = mx in x)


{-| Apply a function that may succeed to all values in the signal, but only keep the successes.

    filterMap f initial == filter initial << map f
-}
filterMap : (a -> Maybe b) -> b -> Signal a -> Signal b
filterMap f initial =
  map f >> filter initial


{-| Apply a fold that may fail, ignore any non-changes. 
-}
filterFold : (a -> b -> Maybe b) -> b -> Signal a -> Signal b
filterFold f initial =
  let
    f' a s =
      let
        res = f a s
      in
        (res, Maybe.withDefault s res)
  in
    foldps f' (Just initial,initial)
    >> filter initial
-- if it was a (a -> Maybe (b -> b)), the implementation would have been easier:
-- filterFold f initial input = filterMap f identity input |> foldp (<|) initial


{-| A function that merges the events of two signals without bias
(unlike `Signal.merge`). It takes a resolution function for the
(usually rare) case that the signals update in the same "round".

    fairMerge (\l r -> l) == merge
-}
fairMerge : (a -> a -> a) -> Signal a -> Signal a -> Signal a
fairMerge resolve left right =
  let
    boolLeft  = always True <~ left
    boolRight = always False <~ right
    bothUpdated = (/=) <~ (merge boolLeft boolRight) ~ (merge boolRight boolLeft)
    
    keep = keepWhenI bothUpdated
    resolved = resolve <~ keep left ~ keep right
    merged = merge left right
  in
    merged |> merge resolved


{-| Combine a list of signals into a signal of lists. We have

      combine = mapMany identity

Also, whenever you are in a situation where you write something like

      Signal.map f (combine signals)

you are better off directly using `mapMany f signals`. -}
combine : List (Signal a) -> Signal (List a)
combine = List.foldr (map2 (::)) (constant [])


{-| Apply a function to the current value of many signals. The
function is reevaluated whenever any signal changes. A typical use case:

      mapMany (flow down) [sig_elem1, sig_elem2, sig_elem3]

Note how this is nicer (and more extendable) than the equivalent:

      Signal.map3 (\e1 e2 e3 -> flow down [e1, e2, e3]) sig_elem1 sig_elem2 sig_elem3

Also, `mapMany List.maximum : List (Signal comparable) -> Signal comparable`
gives a signal that always carries the maximum value from all its
input signals.
-}
mapMany : (List a -> b) -> List (Signal a) -> Signal b
mapMany f l =
  f <~ combine l


{-| Apply functions in a signal to the current value of many signals.
The result is reevaluated whenever any signal changes. 
-}
applyMany : Signal (List a -> b) -> List (Signal a) -> Signal b
applyMany fs l =
  fs ~ combine l
