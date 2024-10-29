import java.util.Random;

// SortThread class for sorting an array segment in a separate thread
class SortThread extends Thread {
  private final int[] array;

  public SortThread(int[] array) {
    this.array = array;
  }

  @Override
  public void run() {
    MultiThreadedMergeSort.mergeSort(array); // Use merge sort recursively on this segment
  }
}

public class MultiThreadedMergeSort {
  public static void main(String[] args) {
    Random rand = new Random();
    int[] numbers = new int[100];

    for (int i = 0; i < numbers.length; i++) {
      numbers[i] = rand.nextInt(1000000);
    }

    System.out.println("Before:");
    printArray(numbers);

    // Start the multi-threaded merge sort
    mergeSort(numbers);

    System.out.println("\nAfter:");
    printArray(numbers);
  }

  // Updated mergeSort to be static so it can be accessed in SortThread
  public static void mergeSort(int[] inputArray) {
    int inputLength = inputArray.length;
    
    if (inputLength < 2) {
      return;
    }
    
    int midIndex = inputLength / 2;
    int[] leftHalf = new int[midIndex];
    int[] rightHalf = new int[inputLength - midIndex];
    
    // Split the array into left and right halves
    System.arraycopy(inputArray, 0, leftHalf, 0, midIndex);
    System.arraycopy(inputArray, midIndex, rightHalf, 0, inputLength - midIndex);
    
    // Create threads for sorting each half
    SortThread leftSorter = new SortThread(leftHalf);
    SortThread rightSorter = new SortThread(rightHalf);

    // Start the sorting threads
    leftSorter.start();
    rightSorter.start();

    try {
      // Wait for both threads to finish
      leftSorter.join();
      rightSorter.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }

    // Merge the sorted halves
    merge(inputArray, leftHalf, rightHalf);
  }

  private static void merge(int[] inputArray, int[] leftHalf, int[] rightHalf) {
    int leftSize = leftHalf.length;
    int rightSize = rightHalf.length;
    
    int i = 0, j = 0, k = 0;
    
    while (i < leftSize && j < rightSize) {
      if (leftHalf[i] <= rightHalf[j]) {
        inputArray[k++] = leftHalf[i++];
      } else {
        inputArray[k++] = rightHalf[j++];
      }
    }
    
    while (i < leftSize) {
      inputArray[k++] = leftHalf[i++];
    }
    
    while (j < rightSize) {
      inputArray[k++] = rightHalf[j++];
    }
  }

  private static void printArray(int[] numbers) {
    for (int number : numbers) {
      System.out.println(number);
    }
  }
}
