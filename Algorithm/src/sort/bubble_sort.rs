pub fn bubble_sort<T:PartialOrd>(arr:&mut[T]){
    for i in 0..arr.len(){
        for j in 0..arr.len()-i-1{
            if arr[j]>arr[j+1]{
                arr.swap(j,j+1);
            }
        }
    }
}
#[cfg(test)]
pub mod test{
    use super::bubble_sort;

    #[test]
    pub fn test_bubble_sort(){
        let mut arr:Vec<f32>=vec![1.9,1.8,1.7,1.6,1.5];
        bubble_sort(&mut arr);
        assert!(arr[0]==1.5);
    }
}