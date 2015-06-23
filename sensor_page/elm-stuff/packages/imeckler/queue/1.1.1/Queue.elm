module Queue (
  Queue,
  empty,
  push,
  pop,
  isEmpty,
  length,
  map,
  toList
  ) where

{-| Just a simple queue data type.

# Construction
@docs empty, push

# Inspection
@docs pop

# Utilities
@docs isEmpty, length, map, toList
-}

import List exposing ((::))
import Queue.Internal as I
import Queue.Internal exposing (Queue(Queue))

type alias Queue a = I.Queue a

empty : Queue a
empty = Queue [] []

push : a -> Queue a -> Queue a
push x (Queue f b) = (Queue f (x::b))

pop : Queue a -> Maybe (a, Queue a)
pop (Queue f b) = case f of
  [] -> case b of
    [] -> Nothing 
    _  -> let (x :: f') = List.reverse b in Just (x, Queue f' [])
  x :: xs -> Just (x, Queue xs b)

isEmpty : Queue a -> Bool
isEmpty q = case q of
  Queue [] [] -> True
  _           -> False

length : Queue a -> Int
length (Queue f b) = List.length f + List.length b

map : (a -> b) -> Queue a -> Queue b
map g (Queue f b) = Queue (List.map g f) (List.map g b)

toList : Queue a -> List a
toList (Queue f b) = f ++ List.reverse b

