def main():
    # Read the input values
    H = int(input("Enter hours: "))
    M = int(input("Enter minutes: "))

    # Convert hours into minutes
    current_total_minutes = H * 60 + M
    total_minutes_in_a_day = 24 * 60

    # Calculate time left in minutes
    if current_total_minutes < total_minutes_in_a_day:
        time_left_minutes = total_minutes_in_a_day - current_total_minutes
        time_left_hours = time_left_minutes // 60
        time_left_minutes_remaining = time_left_minutes % 60
    else:
        time_exceeded = current_total_minutes - total_minutes_in_a_day
        time_left_hours = -(time_exceeded // 60)
        time_left_minutes_remaining = -(time_exceeded % 60)

    # Print the result in HH::MM format
    print(f"{time_left_hours:02d}::{time_left_minutes_remaining:02d}")

if __name__ == "__main__":
    main()
