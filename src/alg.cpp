// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int start = i, end = len;
    while (1 < end - start) {
      int mid = (start + end) / 2;
      if (arr[i] + arr[mid] == value) {
        count++;
        int k = mid + 1;
        while (arr[i] + arr[k] == value && k < end) {
          count++;
          k++;
        }
        k = mid - 1;
        while (arr[i] + arr[k] == value && k > start) {
          count++;
          k--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value) {
        end = mid;
      }
      else {
        start = mid;
      }
    }
  }
  return count;
}
