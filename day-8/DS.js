function merge(arr, l, mid, r) {
  let n1 = mid - l + 1, n2 = r - mid;
  let L = [], R = [];
  for (let i = 0; i < n1; i++) {
    L.push(arr[i + l]);
  }
  for (let i = 0; i < n1; i++) {
    R.push(arr[mid + i + 1]);
  }
  let i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k++] = L[i++];
    }
    else {
      arr[k++] = R[j++];
    }
  }
  while (i < n1) {
    arr[k++] = L[i++];
  }
  while (j < n2) {
    arr[k++] = R[j++];
  }
}

function merge_sort(arr, l, r) {
  if (l < r) {
    let mid = Math.floor((l + r) / 2);
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    merge(arr, l, mid, r);
  }

}

let arr = [8, 7, 6, 5, 3, 1, 0, 10];
merge_sort(arr, 0, 7);
console.log(arr);

let arr1 = [8, 7, 6, 5, 3, 1, 0, 10];
quick_sort(arr1);
console.log(arr1);
