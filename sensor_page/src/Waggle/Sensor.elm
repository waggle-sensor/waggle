module Waggle.Sensor where

import String
import Dict exposing (..)
import Time exposing (Time)
import QueueBuffer exposing (QueueBuffer)

type alias PhysicalQuantity = String
type alias SensorId = String

type alias SensorBoard = Dict SensorId SensorHistory
type alias SensorHistory = Dict PhysicalQuantity ValueHistory
type alias ValueHistory = QueueBuffer Value

type alias Value = InternalValue { timestamp : Time }
type alias Sensor = { id : String, data : List Value }

{-| Internal types.
 -  Only used in Parse.elm and Update.elm before values are timestamped. -}
type alias InternalValue a = { a | 
    value : Float, 
    units : String, 
    physicalQuantity : PhysicalQuantity
}

type alias InternalSensor = { 
    id : String, 
    data : List (InternalValue {})
}
