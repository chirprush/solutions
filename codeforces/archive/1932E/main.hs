import Control.Monad

f :: String -> Integer -> Integer
f (c:s) p = (read (c:"") :: Integer) * p + (f s (10 * p + 1))
f "" _ = 0

main :: IO ()
main = do
    l <- getLine
    let t = read l :: Integer
    numbers <- forM [1, 2.. t] (\_ -> do
        _ <- getLine
        s <- getLine
        return $ f (reverse s) 1
        )
    mapM_ print numbers
