module Main where

import IO.IO exposing (..)
import IO.Runner exposing (Request, Response, run)

console : IO ()
console = writeFile { file = "Test.txt", content = "Hello, Test!\n" } >>>
          putStrLn "Printed to file: Test.txt"

port requests : Signal Request
port requests = run responses console

port responses : Signal Response
