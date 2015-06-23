module Waggle.View.EnvSense where

import Graphics.Collage exposing (collage)
import Graphics.Element exposing 
    ( Element
    , middle
    , widthOf, midBottom, image, layers
    , flow, down, above, bottomLeft, right 
    , topRight, spacer
    , container, empty, below )
import Text exposing (Text)
import Maybe
import Dict
import List
import Time exposing (Time)

import Util
import QueueBuffer exposing (QueueBuffer)
import Waggle.Sensor exposing (..)
import Waggle.Config as Config exposing (sensor, value, primaryEm)
import Waggle.View.Util exposing 
    ( Side(Left, Right)
    , valueContainer
    , sensorContainer
    , primaryText, marginX, marginY
    , h1, h2 )

{-| Identifies each sensor with its image on the sensor board. -}
pointerStart : SensorId -> (Float, Float)
pointerStart sensorId = case sensorId of
    "MLX90614ESF-DAA.Melexis.008-2013"      -> (35, -187)
    "TMP421.Texas_Instruments.2012"         -> (35, -65)
    "BMP180.Bosch.2_5-2013"                 -> (18, -105)
    "MMA8452Q.Freescale.8_1-2013"           -> (45, -280)
    "Thermistor_NTC_PR103J2.US_Sensor.2003" -> (-10, 80)
    "HTU21D.MeasSpec.2013"                  -> (42, -235)
    "DS18B20.Maxim.2008"                    -> (50, 155)
    "SHT75.Sensirion.5_2011"                -> (45, -10)
    "GA1A1S201WP.Sharp.2007"                -> (45, 40)

    "PDV_P8104.API.2006"                    -> (-32, 35)
    "HIH4030.Honeywell.2008"                -> (-23, -102)
    "SHT15.Sensirion.4_3-2010"              -> (-28, 117)
    "RHT03.Maxdetect.2011"                  -> (-10, 210)
    "TMP102.Texas_Instruments.2008"         -> (-23, -240)
    "MAX4466.Maxim.2001"                    -> (-32, -20) -- sound
    "D6T-44L-06.Omron.2012"                 -> (-65, -160)
    "HMC5883.Honeywell.2013"                -> (-45, -280)
    "HIH6130.Honeywell.2011"                -> (-23, -160)

    _                                       -> (0, 0)

index : SensorId -> Int
index sensorId = case sensorId of
    "MLX90614ESF-DAA.Melexis.008-2013"      -> 7
    "TMP421.Texas_Instruments.2012"         -> 5
    "BMP180.Bosch.2_5-2013"                 -> 6
    "MMA8452Q.Freescale.8_1-2013"           -> 9
    "Thermistor_NTC_PR103J2.US_Sensor.2003" -> 2
    "HTU21D.MeasSpec.2013"                  -> 8
    "DS18B20.Maxim.2008"                    -> 1
    "SHT75.Sensirion.5_2011"                -> 4
    "GA1A1S201WP.Sharp.2007"                -> 3

    "PDV_P8104.API.2006"                    -> 3
    "HIH4030.Honeywell.2008"                -> 5
    "SHT15.Sensirion.4_3-2010"              -> 2
    "RHT03.Maxdetect.2011"                  -> 1
    "TMP102.Texas_Instruments.2008"         -> 8
    "MAX4466.Maxim.2001"                    -> 4
    "D6T-44L-06.Omron.2012"                 -> 7
    "HMC5883.Honeywell.2013"                -> 9
    "HIH6130.Honeywell.2011"                -> 6

    _                                       -> 0

order : SensorId -> SensorId -> Order
order s1 s2 = compare (index s1) (index s2) 

name : SensorId -> String
name sensorId = case sensorId of
    "MLX90614ESF-DAA.Melexis.008-2013"      -> "MLX90614ESF"
    "TMP421.Texas_Instruments.2012"         -> "TMP421"
    "BMP180.Bosch.2_5-2013"                 -> "BMP180"
    "MMA8452Q.Freescale.8_1-2013"           -> "MMA8452Q"
    "Thermistor_NTC_PR103J2.US_Sensor.2003" -> "PR103J2"
    "HTU21D.MeasSpec.2013"                  -> "HTU21D"
    "DS18B20.Maxim.2008"                    -> "DS18B20"
    "SHT75.Sensirion.5_2011"                -> "SHT75"
    "GA1A1S201WP.Sharp.2007"                -> "GA1A1S201WP"

    "PDV_P8104.API.2006"                    -> "PDVP8104"
    "HIH4030.Honeywell.2008"                -> "HIH4030"
    "SHT15.Sensirion.4_3-2010"              -> "SHT15"
    "RHT03.Maxdetect.2011"                  -> "RHT03"
    "TMP102.Texas_Instruments.2008"         -> "TMP102"
    "MAX4466.Maxim.2001"                    -> "MAX4466"
    "D6T-44L-06.Omron.2012"                 -> "D6T44L06"
    "HMC5883.Honeywell.2013"                -> "HMC5883"
    "HIH6130.Honeywell.2011"                -> "HIH6130"

    _                                       -> "Error: " ++ sensorId ++ " not recognized."  

side : SensorId -> Side
side sensorId = case sensorId of
    "MLX90614ESF-DAA.Melexis.008-2013"      -> Right
    "TMP421.Texas_Instruments.2012"         -> Right
    "BMP180.Bosch.2_5-2013"                 -> Right
    "MMA8452Q.Freescale.8_1-2013"           -> Right
    "Thermistor_NTC_PR103J2.US_Sensor.2003" -> Right
    "HTU21D.MeasSpec.2013"                  -> Right
    "DS18B20.Maxim.2008"                    -> Right
    "SHT75.Sensirion.5_2011"                -> Right
    "GA1A1S201WP.Sharp.2007"                -> Right

    "PDV_P8104.API.2006"                    -> Left
    "HIH4030.Honeywell.2008"                -> Left
    "SHT15.Sensirion.4_3-2010"              -> Left
    "RHT03.Maxdetect.2011"                  -> Left
    "TMP102.Texas_Instruments.2008"         -> Left
    "MAX4466.Maxim.2001"                    -> Left
    "D6T-44L-06.Omron.2012"                 -> Left
    "HMC5883.Honeywell.2013"                -> Left
    "HIH6130.Honeywell.2011"                -> Left 

    _                                       -> Left

{-| Helper function used in magneticField and acceleration. -}
viewXYZ : String -> SensorId -> SensorHistory -> List (String, ValueHistory)
viewXYZ prefix sensorId history = 
    let component suffix = 
        let measurement : String 
            measurement = prefix ++ suffix 
            -- ^ required b/c of compiler bug (see elm-compiler/issues/880)
        in Dict.get measurement history
            |> Maybe.withDefault (QueueBuffer.empty 0)
            |> (,) (prefix ++ " " ++ suffix)
    
    in [ component "X", component "Y", component "Z" ]

magneticField : SensorId -> SensorHistory -> SensorHistory
magneticField sensorId sensorHistory = Dict.fromList
    <| viewXYZ "Magnetic Field" sensorId sensorHistory

acceleration : SensorId -> SensorHistory -> SensorHistory
acceleration sensorId history = 
    let vibration = (Dict.get "Vibration" history)
            |> Maybe.withDefault (QueueBuffer.empty 0)

        xyz : List (String, ValueHistory)
        xyz = viewXYZ "Acceleration" sensorId history

    in Dict.fromList 
       <| ("RMS Vibration", vibration) :: xyz
       
infraRedCamera : SensorHistory -> SensorHistory
infraRedCamera history = 
    let casing = "TemperaturePTAT"

        average : Int -> Value -> Value
        average n sumTotal = { sumTotal | value <- sumTotal.value / toFloat n }

        byTimestamp : Value -> Value -> Bool 
        byTimestamp v1 v2 = v1.timestamp == v2.timestamp

        sumValues : Value -> Value -> Value
        sumValues v1 v2 = { v1 | value <- v1.value + v2.value } 

        averageTemperature : ValueHistory
        averageTemperature = QueueBuffer.fromList Config.historySize 
            <| Util.groupFold byTimestamp sumValues (\v -> { v | value <- 0 })
            <| List.concatMap QueueBuffer.toList
            <| Dict.values (Dict.remove casing history)

        casingTemperature : ValueHistory
        casingTemperature = Dict.get casing history
            |> Maybe.withDefault (QueueBuffer.empty 0)

    in Dict.fromList
        [ ("Casing Temperature", casingTemperature)
        , ("Average Temperature", averageTemperature) ]

