pub fn insertion_sort<T:PartialOrd>(arr:&mut[T]){
    for i in 1..arr.len(){
        let mut j=i-1;
        while arr[j]>arr[j+1]{
            arr.swap(j, j+1);
            if j==0{
                break;
            }
            j-=1;
        }
    }
}

#[cfg(test)]
pub mod test{
    use super::insertion_sort;
    #[test]
    fn test_insert_sort(){
        let mut arr:Vec<f32>=vec![1.9,1.8,1.7,1.6,1.5];
        insertion_sort(&mut arr);
        assert_eq!(arr[0],1.5);
    }
}