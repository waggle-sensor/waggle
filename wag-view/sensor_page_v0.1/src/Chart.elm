module Chart where

import Graphics.Element exposing (Element, empty, spacer)
import Graphics.Collage as Collage 
import Color
import Signal exposing (Signal, map, constant)
import Signal.Extra exposing (runBuffer)
import List

import QueueBuffer exposing (QueueBuffer)

type alias Point a = (a, a)

-- What about when the max or min is negative?
chart : { width : Int, height : Int } -> QueueBuffer (Point Float) -> Element
chart { width, height } buf = 
    let data = QueueBuffer.toList buf
    in case List.unzip data of
        -- Only want to display a chart if there are two or more points.
        (x :: xs :: xss, y :: ys :: yss) -> 
            let xs' = xs :: xss
                ys' = ys :: yss
                
                dataBbox =
                -- List.maximum and List.minimum are not total functions.
                -- Folding using max and min is safer.
                { x = { max = List.foldr max x xs', min = List.foldr min x xs' }
                , y = { max = List.foldr max y ys', min = List.foldr min y ys' }
                }
        
                (marginX, marginY) = (2, 2)

                -- Width and height of the chart, excluding margins 
                w = width - 2 * marginX |> toFloat
                h = height - 2 * marginY |> toFloat
 
                -- Offset on the chart. Divide by 2 because the offset is 
                -- added from the origin, which is at the center of the chart.
                xOffset = w * (toFloat buf.available / maxSize) / 2
           
                maxSize : Float
                maxSize = QueueBuffer.maxSize buf |> toFloat

                -- The number of elements actually in the QueueBuffer. 
                size : Float
                size = List.length data |> toFloat

                dataXMid = dataBbox.x.min + (dataBbox.x.max - dataBbox.x.min) / 2
                dataYMid = dataBbox.y.min + (dataBbox.y.max - dataBbox.y.min) / 2

                -- Scaling factors to map the bounding box for the data onto the 
                -- visual bounding box for the chart element.
                xScale = w * (size / maxSize) / (dataBbox.x.max - dataBbox.x.min)
                yScale = h / (dataBbox.y.max - dataBbox.y.min)

                -- Map the center of the data to the center of the chart (adjusted
                -- to fit the # of available data points and scale appropriately.
                fit : Point Float -> Point Float 
                fit (x, y) = 
                    ( xOffset + (x - dataXMid) * xScale
                    , (y - dataYMid) * yScale 
                    )

                dot : Point Float -> Collage.Form
                dot (x,y) = Collage.move (fit (x,y))
                    <| Collage.filled Color.red (Collage.circle 2) 

                lineChart : Collage.Form
                lineChart = List.map fit data
                    |> Collage.path 
                    |> Collage.traced (Collage.solid Color.black) 

                latest : Collage.Form
                latest = QueueBuffer.mapLast dot (Collage.toForm empty) buf

            in Collage.collage width height [ lineChart, latest ]
        _ -> spacer width height

