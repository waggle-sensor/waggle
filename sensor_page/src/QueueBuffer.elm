module QueueBuffer where

import Queue
import Queue.Internal exposing (Queue(Queue))
import List

type alias QueueBuffer a = {
    queue : Queue a,
    available : Int
}

push : a -> QueueBuffer a -> QueueBuffer a
push x buf = 
    if | buf.available == 0 ->
        case Queue.pop buf.queue of
            Just (_, queue) -> { buf | queue <- Queue.push x queue }
            Nothing -> { buf | queue <- Queue.push x Queue.empty }
       | otherwise -> { buf 
            | queue <- Queue.push x buf.queue
            , available <- buf.available - 1 }

empty : Int -> QueueBuffer a
empty bufSize = { queue = Queue.empty, available = bufSize }

toList : QueueBuffer a -> List a
toList buf = Queue.toList buf.queue

-- TODO: Replace with a more efficient implementation.
-- This will require adding fromList to the Queue library.
fromList : Int -> List a -> QueueBuffer a
fromList bufSize = List.foldl push (empty bufSize)

maxSize : QueueBuffer a -> Int
maxSize buf = buf.available + Queue.length buf.queue

last : QueueBuffer a -> Maybe a
last = mapLast Just Nothing

mapLast : (a -> b) -> b -> QueueBuffer a -> b
mapLast f default buf = case buf.queue of 
    Queue h t -> case t of
        last :: _     -> f last
        [] -> case h of
            []        -> default
            last :: _ -> f last

map : (a -> b) -> QueueBuffer a -> QueueBuffer b
map f buf = { buf | queue <- Queue.map f buf.queue }

