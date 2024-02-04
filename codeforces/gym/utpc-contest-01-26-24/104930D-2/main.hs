m :: Int
m = 1000000007

rec :: Int -> Int -> Int -> Int -> Int
rec n i p u
    | i == n = 1
    | otherwise = (sum (map (\j -> rec n (i + 1) j u) [p + 1, p + 2..13]) + if u < 4 then rec n (i + 1) 1 (u + 1) else 0) `mod` m

main = print $ map (\n -> rec n 0 1 0) [1..20]
