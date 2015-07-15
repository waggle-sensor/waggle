module Main where

import IO.IO exposing (..)
import IO.Runner exposing (Request, Response, run)

console = forever (putStrLn "sup")

port requests : Signal Request
port requests = run responses console

port responses : Signal Response
