module Queue.Internal (Queue(..)) where

{-| Internal representation of the queue type. -}

type Queue a = Queue (List a) (List a)

