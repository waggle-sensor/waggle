module Main where

import IO.IO exposing (..)
import IO.Runner exposing (Request, Response)
import IO.Runner as Run

import String

hugeString () = String.concat <| List.repeat 100000000000 "blah "

port requests : Signal Request
port requests = Run.run responses (putStrLn "hah" >>= \_ -> putStrLn (hugeString ()))

port responses : Signal Response
