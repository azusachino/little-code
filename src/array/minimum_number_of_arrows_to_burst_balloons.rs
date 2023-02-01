use crate::Solution;

impl Solution {
    pub fn find_min_arrow_shots(points: Vec<Vec<i32>>) -> i32 {
        let mut points = points;
        //  Sort based on ending values
        points.sort_by_key(|x| x[1]);
        let mut endpoint = points[0][1];
        //  if x is between points[0] and points[1]
        points[..].iter().fold(1, |mut count, point| {
            if point[0] > endpoint {
                count += 1;
                endpoint = point[1]
            }
            count
        }) as i32
    }
}