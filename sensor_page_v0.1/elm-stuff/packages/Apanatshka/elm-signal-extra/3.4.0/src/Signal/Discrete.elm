module Signal.Discrete(EventSource, es, whenEqual, whenChange, whenChangeTo, folde) where
{-| Helper functions for recognising events. Mostly useful in
combination with `Signal.sampleOn`, although there are uses. 

# EventSource
An `EventSource` is really just a `Signal` where we don't care about its
value, but only when it updates. A prime example is `Mouse.clicks`. 
@docs EventSource, es

# Basics
@docs whenEqual, whenChange, whenChangeTo

# `foldp` variations
@docs folde
-}

import Signal exposing ((<~), (~), Signal)

{-| At some point in the future Elm will probably support something like
this:

    type alias EventSource = Signal _

That is, `EventSource` will become an alias for any `Signal a` where we
hide the `a` part.  
Until then, there is the `es` function to create an EventSource
-}
type alias EventSource =
  Signal ()

{-| Simple way to make an event signal from any signal
-}
es : Signal a -> EventSource
es = Signal.map (always ())

{-| Fires when the value of the input signal is equal to the given
value.

**NB:** Repeated updates to the same value will make the `EventSource`
fire repeatedly.  
See also: [`whenChangeTo`](#whenChangeTo). 

    Mouse.clicks == whenEqual True Mouse.isDown
-}
whenEqual : a -> Signal a -> EventSource
whenEqual value input =
  let
    keepIf = Signal.filter
    matchEvent = 
      keepIf ((==) value) value input
  in
    es matchEvent

{-| Fires when the value of the input signal changes. 
-}
whenChange : Signal a -> EventSource
whenChange input =
  es <| Signal.dropRepeats input

{-| Fires when the value of the input signal changes to the given value.

    spacebarPress = whenChangeTo True Keyboard.spacebar
-}
whenChangeTo: a -> Signal a -> EventSource
whenChangeTo value input =
  whenEqual value <| Signal.dropRepeats input

{-| `foldp` on an `EventSource`.

    toggleOnEnter = folde not False <| whenChangeTo True Keyboard.enter
-}
folde : (b -> b) -> b -> EventSource -> Signal b
folde step base evt =
  Signal.foldp (\_ b -> step b) base evt
