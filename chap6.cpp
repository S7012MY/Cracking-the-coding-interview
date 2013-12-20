//6.1
//3 1 3 6 = 8
//(3+1)/3*6

//6.2
//Each domino covers a black and a white square, by taking 2 oposite corners we take 2 white or 2 black
//ones so we remain with 2 uncovered squares

//6.3
//5,0|2,3|2,0|0,2|5,2|4,3

//6.4
//Induction
//P(1) if there is one hat then it takes one night to remove it
//If one sees no hat then it must have a hat because c(number of hats)>0 => P(1) is true
//P(2) if no hat is removed after first night then the person who sees only one hat concludes that he
//has a hat and the hats are removed after day 2
//Assume P(N) is true, we have to prove that P(N+1) is true
//Each person who has a hat sees that the hats did not dissapear after N days and sees N hats so
//now he knows that has a hat so next day all hats dissapear

//6.5
//To have a good strategy the number of drops of the first egg + the number of drops of the second head must
//be the same for all cases. So if we drop first time the egg from Xth floor, next time we have to drop it from
//X+X-1th floor. Because we'll need X-2 drops to find the exact floor for which the egg breaks
//We have now to solve X+X-1+...+1=100. X(X+1)=200 X~=14

//6.6
//Only the numbers with odd number of divisors remain open
//Only the perfect squares have odd number of divisors because each divisor contributes with 
//another one: i,(N/i) and sqrt(number) contributes only with one
//We have 10 perfect squares in 1...100
