{-# LANGUAGE OverloadedStrings #-}
import Data.Char ()
import System.Exit (die)
import System.Environment
import System.IO (hFlush, stdout)

main = do
  args <- getArgs
  contents <- readFile $ head args
  if 999 `notElem` concatMap (statesHelper 0 . init) (filter (not . null) $ lines contents)
    then putStr ""
    else die "Se encontraron palabras no reconocidas en el archivo introducido"
  let lexed = concatMap (simplifyTokens . tokens) (filter (not . null) $ lines contents)
  putStr lexed

simplifyTokens :: [(String,Int)] -> String
simplifyTokens [] = ""
simplifyTokens ((token,state):xs) = show state ++ " " ++ token ++ "\n" ++ simplifyTokens xs


tokens :: String -> [(String, Int)]
tokens text = zip (getTokens text) (getTokenStates $ getStates text)

getTokens :: String -> [String]
getTokens text = split (addDelimiters text (getStates text)) '~'

getStates :: String -> [Int]
getStates text = removeOne $ statesHelper 0 (text ++ " ")

statesHelper :: Int -> String -> [Int]
statesHelper _ [] = []
statesHelper 6 [x] = [106]
statesHelper prevState (x : chars) =
  let current
        | prevState < 100 = nextState prevState x
        | otherwise = nextState 0 x
   in if current < 100
        then current : statesHelper current chars
        else
          if current /= 999
            then current : nextState 0 x : statesHelper (nextState 0 x) chars
            else current : statesHelper (nextState 0 x) chars

tokenToText :: [(String, Int)] -> String
tokenToText = tokenTextHelper

tokenTextHelper :: [(String, Int)] -> String
tokenTextHelper [] = []
tokenTextHelper ((token, state) : xs)
  --"Tipo                    Token\n"
  | state == 101 = "Variable               " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 102 = "Asignacion             " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 103 = "Suma                   " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 104 = "Resta                  " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 105 = "Division               " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 106 = "Comentario             " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 107 = "Multiplicacion         " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 108 = "Exponente              " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 109 = "Parentesis que abre    " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 110 = "Parentesis que cierra  " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 111 = "Numero                 " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs
  | state == 999 = "Error                  " ++ removeWhitespace token ++ "\n" ++ tokenTextHelper xs

addDelimiters :: String -> [Int] -> String
addDelimiters [] _ = []
addDelimiters _ [] = []
addDelimiters [c] _ = [c]
addDelimiters (c : xc) (s : xs) = if s > 100 then c : '~' : addDelimiters xc xs else c : addDelimiters xc xs

split :: String -> Char -> [String]
split [] delim = [""]
split (c : cs) delim
  | c == delim = "" : rest
  | otherwise = (c : head rest) : tail rest
  where
    rest = split cs delim

removeOne :: [Int] -> [Int]
removeOne [] = []
removeOne [n1] = []
removeOne [n1, n2] = if n2 > 100 && n2 /= 999 then [n2] else [n1, n2]
removeOne (n1 : n2 : xs)
  | n2 < 100 = n1 : removeOne (n2 : xs)
  | n2 == 999 = n1 : removeOne (n2 : xs)
  | otherwise = removeOne (n2 : xs)

nextState :: Int -> Char -> Int
nextState state char
  | char == ' ' = head stateList
  | char == 'E' || char == 'e' = stateList !! 13
  | char `elem` ['a' .. 'z'] = stateList !! 1
  | char `elem` ['A' .. 'Z'] = stateList !! 2
  | char == '_' = stateList !! 3
  | char `elem` ['0' .. '9'] = stateList !! 4
  | char == '=' = stateList !! 5
  | char == '+' = stateList !! 6
  | char == '-' = stateList !! 7
  | char == '/' = stateList !! 8
  | char == '*' = stateList !! 9
  | char == '^' = stateList !! 10
  | char == '(' = stateList !! 11
  | char == ')' = stateList !! 12
  | char == '.' = stateList !! 14
  | otherwise = stateList !! 15
  where
    e = 999
    stateMatrix =
      [ {- space     [a..z]   [A..Z]    _     [0..9]     =    +     -     /     *    ^   (     )     E/e  .  else-}
        {- 0 -} [0, 1, 1, e, 11, 2, 3, 4, 5, 7, 8, 9, 10, 8, e, e],
        {- 1 -} [101, 1, 1, 1, 1, 101, 101, 101, 101, 101, 101, 101, 101, 1] ++ repeat 101,
        {- 2 -} repeat 102,
        {- 3 -} repeat 103,
        {- 4 -} repeat 104,
        {- 5 -} replicate 8 105 ++ [6] ++ repeat 105,
        {- 6 -} repeat 6,
        {- 7 -} repeat 107,
        {- 8 -} repeat 108,
        {- 9 -} repeat 109,
        {- 10-} repeat 110,
        {- 11-} replicate 4 111 ++ [11] ++ replicate 9 111 ++ [12] ++ repeat 111,
        {- 12-} replicate 4 111 ++ [12] ++ repeat 111
      ]
    stateList = stateMatrix !! state

getTokenStates :: [Int] -> [Int]
getTokenStates [] = []
getTokenStates (x : xs) =
  if x > 100
    then x : getTokenStates xs
    else getTokenStates xs

removeWhitespace :: String -> String
removeWhitespace (x : xs) =
  if x == ' '
    then removeWhitespace xs
    else x : xs
