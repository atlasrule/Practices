pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
    accounts.iter()
            .map(|x| x.iter().sum()) // Row sums
            .max()                  // max row sum
            .unwrap()              // unwrap the results
}

fn main() {
    let accounts = vec![
        vec![1, 2, 3, 4],
        vec![5, 6, 7, 8],
        vec![9, 10, 11, 12]
    ];
  
    let max_wealth = maximum_wealth(accounts);
    println!("Maximum wealth: {}", max_wealth);
}
