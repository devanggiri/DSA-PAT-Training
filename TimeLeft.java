import java.util.Scanner;

public class TimeLeft {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int H = s.nextInt();
        int M = s.nextInt();

        // Convert hours into minutes
        int currentTotalMinutes = H * 60 + M;

        // Calculate time left in minutes
        int timeLeftMinutes = 24 * 60 - currentTotalMinutes;

        // Convert time left to hours and minutes
        int timeLeftHours = timeLeftMinutes / 60;
        int timeLeftMinutesRemaining = timeLeftMinutes % 60;

        // Print the result in HH::MM format
        System.out.printf("%02d::%02d%n", timeLeftHours, timeLeftMinutesRemaining);
    }
}
