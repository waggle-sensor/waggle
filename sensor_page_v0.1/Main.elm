module Main where

import Dict
import Graphics.Element exposing (Element)
import Http
import Signal
import Task exposing (Task, andThen)
import Window

import Waggle.Update exposing (getData, sensorData)
import Waggle.View exposing (view)

main : Signal Element
main = Signal.map2 view Window.dimensions sensorData

port readData : Signal (Task Http.Error ())
port readData = getData
       
