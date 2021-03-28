data Node = EmptyNode | Node Int Node Node

profundidadNodo :: Int -> Node -> Maybe Int
profundidadNodo num root = profundidadHelper num root 0

profundidadHelper :: Int ->  Node -> Int -> Maybe Int
profundidadHelper num (Node value left right) it
  | num > value = profundidadHelper num right ( it+1 )
  | num < value = profundidadHelper num left ( it+1 )
  | num == value = Just it

mayorGrado :: [[Char]] -> Int
mayorGrado = maximum . map (\n -> length n -1)

maximum' :: (Ord a) => [a] -> a
maximum' = foldr1 (\x1 x2 -> if x1 > x2 then x1 else x2)
