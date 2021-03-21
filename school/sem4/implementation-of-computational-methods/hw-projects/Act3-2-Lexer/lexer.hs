{-# LANGUAGE OverloadedStrings #-}
import System.IO
import Data.Char

main = do
  putStrLn "Ingrese el nombre del archivo"
  hFlush stdout
  file <- getLine
  contents <- readFile file
  let lexed = "Tipo                    Token\n\n": lexer (lines contents)
  putStr $ concat lexed

lexer :: [[Char]] -> [[Char]]
lexer = map lexLine 

lexLine :: [Char] -> [Char]
lexLine = tokenToText . tokens

{- Function to:
  Get current state with previous state
  recall function with list without current char
  pass state 0 if over 100 add state to return value
  pass current is less than 100
-}

tokens :: [Char] -> [([Char],Int)]
tokens text = zip (getTokens text) (getTokenStates $ getStates text)

getTokens :: [Char] ->  [[Char]]
getTokens text = split (addDelimiters text (getStates text)) '~'

getStates :: [Char] ->[Int]
getStates text = init $ removeOne $ statesHelper 0 ( text ++ " " )

statesHelper :: Int -> [Char] -> [Int]
statesHelper _ [] = []
statesHelper prevState (x:chars) =
  let
  current = if prevState < 100 then nextState prevState x else nextState 0 x
  in if current < 100 && current /= 999
  then current: statesHelper current chars
  else if current /= 999
  then current:nextState 0 x: statesHelper (nextState 0 x) chars
  else  current:statesHelper 0 (tail chars)

tokenToText :: [([Char],Int)] -> [Char]
tokenToText = tokenTextHelper

tokenTextHelper :: [([Char],Int)] -> [Char]
tokenTextHelper [] = []
tokenTextHelper ((token,state):xs)
                          --"Tipo                    Token\n"
  | state == 101          = "Variable               " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 102          = "Asignacion             " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 103          = "Suma                   " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 104          = "Resta                  " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 105          = "Division               " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 106          = "Comentario             " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 107          = "Multiplicacion         " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 108          = "Exponente              " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 109          = "Parentesis que abre    " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 110          = "Parentesis que cierra  " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 111          = "Numero                 " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 999          = "Error                  " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs

addDelimiters :: [Char] -> [Int] ->  [Char]
addDelimiters [] _ = []
addDelimiters _ [] = []
addDelimiters (c:[]) _ = [c]
addDelimiters (c:xc) (s:xs) = if s > 100 then c:'~':addDelimiters xc xs else c:addDelimiters xc xs

split :: String -> Char -> [String]
split [] delim = [""]
split (c:cs) delim
    | c == delim = "" : rest
    | otherwise = (c : head rest) : tail rest
    where
        rest = split cs delim

removeOne :: [Int] -> [Int]
removeOne [] = []
removeOne (n1:n2:[]) = if n2 > 100 && n2 /= 999 then n2:[] else n1:n2:[]
removeOne (n1:n2:xs)
  | n2 < 100               = n1:removeOne (n2:xs)
  | n2 == 999              = n1:removeOne (n2:xs)
  | otherwise              = removeOne (n2:xs)

nextState :: Int -> Char -> Int
nextState state char
  | char == ' '            = head stateList
  | char == 'E'||char=='e' = stateList !! 13
  | char `elem` ['a'..'z'] = stateList !! 1
  | char `elem` ['A'..'Z'] = stateList !! 2
  | char == '_'            = stateList !! 3
  | char `elem` ['0'..'9'] = stateList !! 4
  | char == '='            = stateList !! 5
  | char == '+'            = stateList !! 6
  | char == '-'            = stateList !! 7
  | char == '/'            = stateList !! 8
  | char == '*'            = stateList !! 9
  | char == '^'            = stateList !! 10
  | char == '('            = stateList !! 11
  | char == ')'            = stateList !! 12
  | char == '.'            = stateList !! 14
 
  | otherwise              = last stateList
  where e = 999
        stateMatrix = [
         {- space     [a..z]   [A..Z]    _     [0..9]     =    +     -     /     *    ^   (     )     E/e  .  else-}
   {- 0 -} [   0,       1,       1,      e,      11,      2,   3,    4,    5,    7,   8,  9,    10,   8,   e, e    ],
   {- 1 -} [   101,     1,       1,      1,      1] ++ repeat 101,
   {- 2 -} repeat 102,
   {- 3 -} repeat 103,
   {- 4 -} repeat 104,
   {- 5 -} replicate 8 105  ++ [6] ++ repeat 105,
   {- 6 -} repeat 6,
   {- 7 -} repeat 107,
   {- 8 -} repeat 108,
   {- 9 -} repeat 109,
   {- 10-} repeat 110,
   {- 11-} replicate 4 111 ++ [11] ++ replicate 9 111 ++ [12]++repeat 111,
   {- 12-} replicate 4 111 ++ [12] ++ repeat 111

         ]
        stateList = stateMatrix !! state

getTokenStates :: [Int] -> [Int]
getTokenStates [] = []
getTokenStates (x:xs) =
  if x > 100
  then x:getTokenStates xs
  else getTokenStates xs

removeWhitespace :: [Char] -> [Char]
removeWhitespace (x:xs) = if x == ' '
  then removeWhitespace xs
  else x:xs
