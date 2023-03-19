#[warn(dead_code)]
#[allow(dead_code)]
pub struct MaxHeap<T: PartialEq+Copy>{
    data:Vec<T>
}
impl<T:PartialOrd+Copy>MaxHeap<T>{
    pub fn new()->MaxHeap<T>{
        Self { 
            data:Vec::new()
         }
    }
    pub fn new_with_size(size:usize)->MaxHeap<T>{
        Self{
            data:Vec::with_capacity(size)
        }
    }
    pub fn get_size(&self)->usize{
        self.data.len()
    }
    fn parent(&self,index:usize)->Option<usize>{
        if index == 0{
            return None;
        }
        Some((index-1)/2)
    }
    fn lson(&self,index:usize)->usize{
        index<<1|1
    }
    fn rson(&self,index:usize)->usize{
        index<<1+2
    }
    pub fn add(&mut self,ele:T){
        self.data.push(ele);
        self.hang_up(self.data.len()-1);
    }
    pub fn is_empty(&self)->bool{
        self.data.is_empty()
    }
    fn hang_up(&mut self,mut index:usize){//from bottom to up, adjust the element
        while index>0{
            let pa=self.parent(index);
            if let Some(pa_id)=pa{
                if self.data.get(pa_id)<self.data.get(index){
                    self.data.swap(index, pa_id);
                    index=pa_id;
                }
                else{
                    break;
                }
            }else{
                return
            }
        }
    }
    pub fn get_max_element(&self)->Option<T>{
        if self.data.len()==0{
            return None;
        }
        return Some(self.data[0]);
    }
    //swap the last element and the first element, then 
    pub fn extract_max_element(&mut self)->Option<T>{
        let res=self.get_max_element();
        let last_id=self.data.len()-1;
        self.data.swap(0,last_id );
        self.data.remove(last_id);
        self.hang_down(0);
        res
    }
    fn hang_down(&mut self,mut index:usize){
        let res=self.lson(index);
        while self.lson(index)<self.data.len(){
            let mut left=self.lson(index);
            if left+1<self.data.len() && self.data.get(left+1)>self.data.get(left){
                left+=1
            }
            if self.data.get(index)>self.data.get(left){
                break;
            }
            self.data.swap(left, index);
            index=left;
        }
    }
    pub fn replace(&mut self,ele:T)->Option<T>{
        let res=self.get_max_element();
        self.data.insert(0, ele);
        self.hang_down(0);
        res
    }
    pub fn transfer_to_heap(&mut self,data:Vec<T>)->bool{
        self.data=data;
        if self.data.len()!=1{
            let pa_id=self.parent(self.data.len()-1);
            match pa_id{
                None=>false,
                Some(pa_id)=>{
                    let mut i=pa_id as i32;
                    while i>=0{
                        self.hang_down(i as usize);
                        i-=1;
                    }
                    true
                }
            };
        }
        return true;
    }

}

#[cfg(test)]
pub mod test{
    use crate::heap::*;

    use super::MaxHeap;
    #[test]
    pub fn test_heap(){
        let mut heap=MaxHeap::new();
        assert!(heap.is_empty()==true);
        for i in 1..10{
            heap.add(i);
        }
        assert_eq!(heap.get_max_element().unwrap(),9);
        heap.extract_max_element();
        assert_eq!(heap.get_max_element().unwrap(),8);
    }
}