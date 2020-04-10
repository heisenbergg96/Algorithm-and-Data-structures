import java.util.Random;

class Main {

    public static void main(String args[]) {
        
        GenerateArray.generate(10,10);
    }
}

class GenerateArray {

    public static boolean[][] generate(int row, int column) {

        Random rand = new Random();
        boolean[][] earth = new boolean[row][column];

        for (int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                earth[i][j] = (rand.nextInt(1000) % 2 == 0) ? false : true;
                System.out.println(earth[i][j]);
            }
        }

        return earth;
    }
}