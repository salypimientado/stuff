import System.IO

main = do
  putStrLn "Ingrese el nombre del archivo"
  hFlush stdout
  file <- getLine
  contents <- readFile file
  let lexed = lexer (lines contents)
  putStr $ unlines $ concat $ map (map show) lexed

lexer :: [[Char]] -> [[( Char, Int )]]
lexer = map (map (flip (lexChar) 0))

lexChar :: Char -> Int -> (Char, Int)
lexChar char state
  | char == ' '            = ( char, head stateList )
  | char `elem` ['a'..'z'] = ( char, stateList !! 1 )
  | char `elem` ['A'..'Z'] = ( char, stateList !! 2 )
  | char == '_'            = ( char, stateList !! 3 )
  | char `elem` ['0'..'9'] = ( char, stateList !! 4 )
  | char == '='            = ( char, stateList !! 5 )
  | char == '+'            = ( char, stateList !! 6 )
  | char == '-'            = ( char, stateList !! 7 )
  | char == '/'            = ( char, stateList !! 8 )
  | char == '*'            = ( char, stateList !! 9 )
  | char == '^'            = ( char, stateList !! 10)
  | char == '('            = ( char, stateList !! 11)
  | char == ')'            = ( char, stateList !! 12)
  | otherwise              = ( char, last stateList )
  where e = 999
        stateMatrix = [
         {- space     [a..z]   [A..Z]    _     [0..9]     =    +     -     /     *    ^   (     )     else-}
   {- 0 -} [   0,       1,       1,      e,      e,       2,   3,    4,    5,    7,   8,  9,    10,   e    ],
   {- 1 -} [   101,     1,       1,      1,      1] ++ repeat 101,
   {- 2 -} repeat 102,
   {- 3 -} repeat 103,
   {- 4 -} repeat 104,
   {- 5 -} replicate 8 105  ++ [6] ++ repeat 105,
   {- 6 -} repeat 6,
   {- 7 -} repeat 107,
   {- 8 -} repeat 108,
   {- 9 -} repeat 109,
   {- 10-} repeat 110

         ]
        stateList = stateMatrix !! state
