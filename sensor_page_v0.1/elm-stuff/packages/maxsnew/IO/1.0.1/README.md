IO in Elm [![Build Status](https://travis-ci.org/maxsnew/IO.png?branch=master)](https://travis-ci.org/maxsnew/IO)
=========

This repo provides a library for writing console-based programs in
Elm.

Example
-------
An elm Program:
```haskell
module Main where

import IO.IO (..)
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
        putStrLn "That's all, folks!" >>>
        exit 0

port requests : Signal Request
port requests = IO.run responses hello

port responses : Signal Response
```

link in some javascript and then run:
```
$ elm-make --yes Test.elm raw-test.js
...
$ ./elm-io.sh raw-test.js test.js
$ node test.js
Hello, Console!
I'll echo your input:
hooray
hooray
That's all, folks!
```

Command Line Interface
----------------------

The basic interface is `elm-io.sh infile outfile`, where `infile` is a
compiled Elm file with requests and response signals set up as above
and `outfile` is the desired filename for the compiled output.

Design and Implementation
-------------------------
The implementation is based on the
[IOSpec](http://hackage.haskell.org/package/IOSpec) haskell library.
