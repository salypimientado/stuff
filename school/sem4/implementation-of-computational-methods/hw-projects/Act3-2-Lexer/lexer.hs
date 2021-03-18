import System.IO

main = do
  putStrLn "Ingrese el nombre del archivo"
  hFlush stdout
  file <- getLine
  contents <- readFile file
  lexed <- return $ lexer (lines contents)
  putStr $ unlines $ concat $ map (\line -> map show line) lexed

lexer :: [[Char]] -> [[( Char, Int )]]
lexer lines = map (\line -> map (flip (lexChar) 0) line) lines 

lexChar :: Char -> Int -> (Char, Int)
lexChar char state
  | char `elem` ['a'..'z'] = ( char, stateList !! 0 )
  | char `elem` ['A'..'Z'] = ( char, stateList !! 1 )
  | char == '_'            = ( char, stateList !! 2 )
  | char `elem` ['0'..'9'] = ( char, stateList !! 3 )
  | otherwise              = ( char, last stateList )
  where e = 999
        stateMatrix = [
         {-  [a..z] ~ [A..Z]  ~ _  ~  [0..9]  ~  else-}
   {-0-} [     1   ,   1  ,     999  , e   ,     e  ],
   {-1-} [     1   ,   1  ,     1    , 1   ,     101]
   {-3-}
                ]
        stateList = ( stateMatrix !! state )
