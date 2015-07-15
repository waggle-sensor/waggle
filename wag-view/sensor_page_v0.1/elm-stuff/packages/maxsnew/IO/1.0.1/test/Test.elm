module Main where

import IO.IO exposing (..)
import IO.Runner exposing (Request, Response)
import IO.Runner as IO

import List
import Maybe
import String

echo : IO ()
echo = forever (getLine >>= putStrLn)

loop : IO ()
loop = getLine >>= \s ->
       if s == "exit"
       then pure ()
       else putStrLn s >>> loop
       
hello : IO ()
hello = putStrLn "Hello, Console!" >>>
        putStrLn "I'll echo your input until you say \"exit\":" >>>
        loop >>>
        putStrLn "That's all, folks! Here's some blahs:"  >>>
        putStrLn (String.concat <| List.repeat 100000 "blah ") >>>
        exit 0

port requests : Signal Request
port requests = IO.run responses hello

port responses : Signal Response
