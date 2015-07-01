module Signal.Time(limitRate, dropWithin, settledAfter, startTime, relativeTime, since, delay, timestamp) where
{-| Time related functions for `Signal`s.

# Easy does it
Controlling too frequently changing signals. 
@docs limitRate, dropWithin, settledAfter

# Relative time
@docs startTime, relativeTime

# Re-exports
Some functions from the `Time` module that fit in. 
@docs since, delay, timestamp
-}

import Signal exposing (Signal, (<~), (~))
import Signal.Extra exposing ((~>))
import Signal.Discrete as Discrete
import Time exposing (Time)

{-| Keep only the timestamps
-}
timestamps : Signal a -> Signal Time
timestamps s =
  timestamp s ~> fst


{-| Limits the given signal to the given frequency. 

After an update of the given signal, for 1 / the given frequency seconds
subsequent updates are dropped. The original update that started this
dropping is kept. 

    throttledMouseClicks = limitRate 60 Mouse.clicks

Also known in some areas as a `throttle` function. 
-}
limitRate : number -> Signal a -> Signal a
limitRate freq sig = 
  let
    within newt oldt =
      if newt - oldt > Time.second / freq
        then newt
        else oldt
    windowStart = timestamps sig |> Signal.foldp within 0
  in
    Signal.sampleOn (Discrete.whenChange windowStart) sig


{-| Drops all but the first update of a flurry of updates (a stutter).
The stutter is defined as updates that happen with max. the given time
in between. 

The first update of the given signal is sent through. Then the given
delay is waited. If no other updates arrive during that time, then next
update will be sent through. Any update that arrives within the given
time of the last update is dropped. 

    noDoubleClicks = dropWithin (300 * milliseconds) Mouse.clicks

Also known to some areas as an "immediate" `debounce` function. 
-}
dropWithin : Time -> Signal a -> Signal a
dropWithin delay sig =
  let
    leading = since delay sig |> Discrete.whenChangeTo True
  in
    Signal.sampleOn leading sig


{-| Gives the last update of a flurry of updates (a stutter) after has
settled* for the given time. The stutter is defined as updates that
happen within the given time. * Where settled the signal gets no further
updates for some time, it's **not** relating to the value changes of the
signal. 

After every update of the given signal, the given delay is waited. If no
other updates arrived during that time, the update is sent through. If a
new update arrives within the given time, the previous update is dropped
and the waiting is restarted. So `debounce`-ing a signal that keeps up
the flurry of updates all the time results in a signal that never
updates. 

    tooltip : Signal Bool
    tooltip = 
      merge (always False <~ Mouse.position) 
            (always True <~ (Mouse.position
                            |> settledAfter (500 * Time.millisecond)))

Also known in some areas as a `debounce` function. 
-}
settledAfter : Time -> Signal a -> Signal a
settledAfter delay sig =
  let
    trailing = since delay sig |> Discrete.whenChangeTo False
  in
    Signal.sampleOn trailing sig


{-| The timestamp of the start of the program.
-}
startTime : Signal Time
startTime = Signal.constant () |> timestamps


{-| Turns absolute time signal to time relative to the start of the
program. 

    let tick = Time.every Time.second
    in  Signal.foldp ((+) 1) 0 tick == 
          relativeTime tick ~> Time.inSeconds >> round
-}
relativeTime : Signal Time -> Signal Time
relativeTime s =
  (-) <~ s ~ startTime


{-| A re-export of [Time.since](http://package.elm-lang.org/packages/elm-lang/core/1.0.0/Time#since). 

Takes a time `t` and any signal. The resulting boolean signal is true
for time `t` after every event on the input signal. So ``(second `since`
Mouse.clicks)`` would result in a signal that is true for one second
after each mouse click and false otherwise.
-}
since : Time -> Signal a -> Signal Bool
since = Time.since

{-| A re-export of [Time.delay](http://package.elm-lang.org/packages/elm-lang/core/1.0.0/Time#delay). 

Delay a signal by a certain amount of time. So `(delay second
Mouse.clicks)` will update one second later than any mouse click.
-}
delay : Time -> Signal a -> Signal a
delay = Time.delay


{-| A re-export of [Time.timestamp](http://package.elm-lang.org/packages/elm-lang/core/1.0.0/Time#timestamp). 

Add a timestamp to any signal. Timestamps increase monotonically. When
you create `(timestamp Mouse.x)`, an initial timestamp is produced. The
timestamp updates whenever `Mouse.x` updates.

Timestamp updates are tied to individual events, so `(timestamp
Mouse.x)` and `(timestamp Mouse.y)` will always have the same timestamp
because they rely on the same underlying event (`Mouse.position`).
-}
timestamp : Signal a -> Signal (Time, a)
timestamp = Time.timestamp
