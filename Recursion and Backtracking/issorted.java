class Main {

    public static void main(String args[]) {
        int a[] = {5,2,3,4};
        
        System.out.println(isSorted(a, a.length-1));
    }


    static Boolean isSorted(int a[], int n) {

        if(n == 0) {
            return true;
        }

        return (a[n] > a[n-1])? isSorted(a, n-1) : false;
    }
}