module Main where

import IO.IO exposing (..)
import IO.Runner exposing (Request, Response, run)

console : IO ()
console = putStrLn "Hello, Console!"       >>>
          putStrLn "I'll echo your input:" >>>
          (getLine >>= putStrLn)           >>>
          putStrLn "That's all, folks!"    >>>
          exit 0

port requests : Signal Request
port requests = run responses console

port responses : Signal Response
