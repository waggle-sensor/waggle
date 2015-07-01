module Waggle.Config where

import Time exposing (second)
import Graphics.Element exposing (heightOf, leftAligned)
import Graphics.Collage exposing (defaultLine)
import Color exposing (lightGrey)
import Text exposing (defaultStyle, style, fromString)

{-| The number of readings to hold in memory for each sensor. -}
historySize = 60

{-| How frequently to poll for data updates. -}
updateInterval = 1 * second

{- Styles -}
pointerStyle = { defaultLine | color <- lightGrey , width <- 3 }
sensorBackgroundColor = lightGrey

{- Text styles -}
primaryStyle = { defaultStyle 
    | height <- Just 12
    , typeface <- ["Lato", "sans"] }

headerStyle = { defaultStyle | typeface <- ["EB Garamond", "serif"] }
h1Style = { headerStyle | height <- Just 40 }
h2Style = { headerStyle | height <- Just 30 }

{- Sizes -}
chart = 
    { width = 190
    , height = 20 }

image = 
    { width = 293
    , height = 586 
    , marginX = 32 }

sensor = 
    { width = chart.width + value.width + physicalQuantity.width 
    , height =  value.height + 1 * primaryEm
    , marginY = 2
    , marginX = 8
    , padding = 1 }

value = 
    { width = 90
    , height = chart.height + 1 * primaryEm
    , marginX = 16 }

physicalQuantity = 
    { width = 140
    }

primaryEm = "em" 
    |> fromString 
    |> style primaryStyle 
    |> leftAligned 
    |> heightOf

{- Urls -}
sensorDataUrl = "../data/current.txt"
sensorImageUrl = "./assets/env-sense-cropped.jpg"

{- Content -}
title = "EnvSense V1"
secondary = ""
