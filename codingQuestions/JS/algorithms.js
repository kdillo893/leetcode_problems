// sorts
export function mergeSort(array) {

}

export function quicksort(array) {

}

export function insertionSort(array) {

}

export function bubbleSort(array) {

}

export function selectionSort(array) {

}

export function countingSort(array) {

}

export function heapSort(array) {

}

//searches

/**
  * @param {Int32Array} array, must be sorted
  * return index for found, null if not
  */
export function dumbLinearSearch(value, array) {
  for (let i = 0; i < array.length; i++) {
    if (array[i] == value) {
      return i;
    }
  }

  return null;
}

/**
  * @param {Int32Array} array, must be sorted
  * return index for found, null if not
  */
export function binarySearch(value, array) {

  let upper = array.length;
  let lower = 0
  let i = Math.floor(upper / 2)

  for (let c = 0; lower < i && i < upper; c++) {
    let a = array[i]

    if (a == value) {
      return i;
    } else if (value > a) {
      lower = i + 1;
    } else {
      upper = i;
    }
    i = Math.floor((upper - lower) / 2) + lower
  }

  if (array[i] == value) {
    return i;
  }

  return null;
}

export function dfs(value, nodes) {

}

export function bfs(value, nodes) {

}

// other algs

//pathing:
export function dijkstra() {

}

