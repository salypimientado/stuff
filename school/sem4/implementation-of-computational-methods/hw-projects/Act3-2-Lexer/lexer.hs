import System.IO

main = do
  putStrLn "Ingrese el nombre del archivo"
  hFlush stdout
  file <- getLine
  contents <- readFile file
  putStr contents
