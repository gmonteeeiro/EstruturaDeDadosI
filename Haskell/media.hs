calcMedia :: Float -> Float -> Float
calcMedia g1 g2 = (g1 + 2*g2)/3

ng1 = 8
ng2 = 9

main :: IO ()
main =  do
        putStr "Nota G1: "
        print(ng1)

        putStr "Nota G2: "
        print(ng2)

        putStr "Media: "
        print(calcMedia ng1 ng2)
