module Util where

import Signal exposing (Signal, foldp)
import Maybe exposing (Maybe(..), map, andThen, withDefault)
import List
import String
import Result exposing (toMaybe)

-- Get only the (Just a) values from a list of (Maybe a)s.
-- Unlike map fromJust << filter isJust, this function is statically guaranteed 
-- to never throw a runtime error.
filterJust : List (Maybe a) -> List a
filterJust maybes = case maybes of
    []        -> []
    (x :: xs) -> case x of
        Just y  -> y :: (filterJust xs)
        Nothing -> filterJust xs

take : Int -> Signal a -> Signal (List a)
take n input =
  let next inp prev = List.take n (inp :: prev)
  in foldp next [] input

map3 : (a -> b -> c -> result) -> Maybe a -> Maybe b -> Maybe c -> Maybe result
map3 f a b c = case a of
    Just a' -> case b of
        Just b' -> map (f a' b') c
        Nothing -> Nothing
    Nothing -> Nothing

truncateFloat : Int -> Float -> Float
truncateFloat digits num = 
    let num' = String.split "." (toString num)
    in case num' of
        [] -> num
        x :: [] -> withDefault num (toMaybe <| String.toFloat x)
        x :: xs :: _ -> withDefault num (toMaybe <| String.toFloat <| x ++ "." ++ String.left digits xs)

-- | Group a list of values into a list of lists 
--   according to an equality predicate,
--   then fold over each sublist. Combining these two operations
--   allows the initial value for the fold to be computed from 
--   the seed value for each group.
--
--   Note that groupFold is recursive, and so may 
--   run out of stack frames.
groupFold : (a -> a -> Bool) -- equality predicate used for grouping
    -> (a -> b -> b)         -- folding function
    -> (a -> b)              -- generate initial value for folding
    -> List a                -- initial list
    -> List b
groupFold eq f mkDefault list = case list of
    [] -> []
    (x :: xs) ->
        let (ys, zs) = List.partition (eq x) xs     
            
            foldedGroup = List.foldr f (mkDefault x) (x :: ys)
            
        in foldedGroup :: groupFold eq f mkDefault zs


