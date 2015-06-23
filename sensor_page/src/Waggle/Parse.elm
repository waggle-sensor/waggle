module Waggle.Parse where

import String
import Result exposing (Result(..))
import List
import Maybe exposing (Maybe(..), andThen, map)

import Waggle.Sensor exposing (..)

{-| Parse the current list of sensors, as in data/current/current. -}
parse : String -> List InternalSensor
parse = let
        parseLine line sensors = case parseSensor line of
            Just sensor -> sensor :: sensors
            Nothing -> sensors
    in
        (List.foldr parseLine []) 
            << List.filter (not << String.isEmpty) 
            << String.lines

{-| Parse a single line as a sensor.
 -  If the parse fails at any time, returns Nothing; otherwise, returns (Just sensor). 
 -}
parseSensor : String -> Maybe InternalSensor
parseSensor s =
    let data = String.split "," s
    in case data of
        sensorId :: _ :: values -> 
            let 
                combine str maybeState = case parseValue str of
                    Just val -> map ((::) val) maybeState
                    Nothing -> Nothing
                vs = List.foldr combine (Just []) values
                mkSensor values = { id = sensorId, data = values }
            in
                map mkSensor vs
        _ -> Nothing

parseValue : String -> Maybe (InternalValue {})
parseValue s = case String.split ";" s of
    [physicalQuantity, value, units, extra] -> case String.toFloat value of
        Ok val -> Just {
            physicalQuantity = (parsePhysicalQuantity physicalQuantity) ++ parseExtra extra,
            value = val,
            units = parseUnits units
        } 
        Err _ -> Nothing
    _ -> Nothing

parseExtra : String -> String
parseExtra extra = case extra of
    "none" -> ""
    "non-standard" -> ""
    "Voltage_Divider_5V_PDV_Tap_4K7_GND" -> ""
    "Voltage_Divider_5V_NTC_Tap_68K_GN" -> ""
    "RH" -> ""
    "Barometric" -> ""
    "RMS_3Axis" -> ""
    _ -> extra

parsePhysicalQuantity : String -> PhysicalQuantity
parsePhysicalQuantity physicalQuantity = case physicalQuantity of
    "Acoustic_Intensity" -> "Acoustic Intensity"
    "Luminous_Intensity" -> "Luminous Intensity"
    "Magnetic_Field" -> "Magnetic Field"
    _ -> physicalQuantity

parseUnits : String -> String
parseUnits units = case units of
    "C" -> "&deg;C"
    "F" -> "&deg;F"
    "Units10B0V5" -> " raw A/D" -- (uc) stands for uncalibrated
    "gauss" -> "G"
    _   -> units
