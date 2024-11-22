import System.Random (randomRIO)
import Control.Monad (replicateM)

maximumWealth :: [[Int]] -> Int
maximumWealth = maximum . map sum

generateMatrix :: Int -> Int -> Int -> Int -> IO [[Int]]
generateMatrix m n minV maxV = replicateM m $ replicateM n $ randomRIO (minV, maxV)

main :: IO ()
main = do
    let (m, n, minV, maxV) = (3, 3, -10000, 100000) -- Rows, Columns, Min, Max
    accounts <- generateMatrix m n minV maxV
    mapM_ (putStrLn . unwords . map show) accounts -- Print matrix
    print $ maximumWealth accounts
