function chunkArrayInGroups(arr, size) {
  const newArr = [];
  
  //what if size <= 0?

  let subArr = [];
  for (let i = 0; i < arr.length; i++) {
    subArr.push(arr[i]);

    if (subArr.length === size) {
      newArr.push(subArr);
      subArr = [];
    }
  }

  //for non-perfect lengths, add if not 0 length
  if (subArr.length > 0) {
    newArr.push(subArr);
  }

  return newArr;
}

chunkArrayInGroups(["a", "b", "c", "d"], 2);
