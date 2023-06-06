package basics;

import java.util.*;
import java.util.stream.Collectors;

public class MyImplementation {

    public static String queue() {

        return "";
    }
    
    public static ArrayList<Integer> duplicates(int[] arr, int n) {
        // code here
        ArrayList<Integer> dupes = new ArrayList<Integer>();

        Map<Integer, Integer> vals = new HashMap<Integer, Integer>();

        for (int i = 0; i < n; i++) {
            if (vals.containsKey(arr[i])) {
                vals.replace(arr[i], vals.get(arr[i])+1);
            } else {
                vals.put(arr[i], 0);
            }
        }

        for (Map.Entry<Integer, Integer> entry : vals.entrySet()) {
            if (entry.getValue() > 0)
                dupes.add(entry.getKey());
        }

        if (dupes.isEmpty())
            return new ArrayList<Integer>(List.of(-1));
        
        //sort
        Collections.sort(dupes);

        return dupes;
    }

    //THIS AND PARTITION USED FOR QUICKSORT
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high) {

            int partMid = partition(arr, low, high);

            quickSort(arr, low, partMid - 1);
            quickSort(arr, partMid+1, high);
        }
    }
    int partition (int arr[], int low, int high)
    {
        //code here...

        //place lessers at low index going up...
        int pivot = arr[high];

        for (int j = low; j < high; j++) {
            // is this less than the pivot? if yes, move it..
            if (pivot > arr[j]) {

                //the "low numbers" location moves...
                int temp = arr[j];
                arr[j] = arr[low];
                arr[low] = temp;

                low++;
            }
        }

        //place at top of low (in loop, this ends at the index above)
        int temp = arr[high];
        arr[high] = arr[low];
        arr[low] = temp;

        return low;
    }

    /**
     * Determine like elements within all int arrays A/B/C with lengths n1/n2/n3 respectively.
     * [-1] means that there are no elements... which is kinda dumb if you ask me...
     * @param A
     * @param B
     * @param C
     * @param n1
     * @param n2
     * @param n3
     * @return
     */
    ArrayList<Integer> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
        // code here

        //no additional DS... could sort such that duplicates are at the beginning..
        //ARRAYS ARE SORTED!!!

        int dupeCount = 0;
        //one index for each, i/j/k... start at 0 go to n-1.
        //if inequal, increase the index of lowest
        int i=0, j=0, k = 0;

        while (i < n1 && j < n2 && k < n3) {
            //do they all match in value?
            if (A[i] == B[j] && A[i] == C[k]) {
                //increase dupe count... swap with lowest index in individual arrays...
                int temp = A[i];
                A[i] = A[dupeCount];
                A[dupeCount] = temp;
                B[j] = A[dupeCount];
                B[dupeCount] = temp;
                C[k] = A[dupeCount];
                C[dupeCount] = temp;
                dupeCount++;
                i++;
                j++;
                k++;
            } else {
                //one is not equal to the others; whichever is minimum increase.
                int min = Math.min(A[i], Math.min(B[j], C[k]));
                if (min == A[i]) {
                    i++;
                } else if (min == B[j]) {
                    j++;
                } else if (min == C[k]) {
                    k++;
                }
            }
        }

        if (dupeCount > 0) {
            int finalDupeCount = dupeCount;
            return new ArrayList<Integer>() { {for (int i : Arrays.copyOfRange(A, 0, finalDupeCount)) add(i);  }};
        }

        //no match case.
        return new ArrayList<Integer>(List.of(-1));
    }
}
