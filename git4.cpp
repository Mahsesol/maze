

//functions to find the max and min element in a 2D vector (for solving and playing user uploaded maze)
int minelement(vector<vector<int>> matrix) {
    int min = std::numeric_limits<int>::max();

    for_each(matrix.begin(), matrix.end(),
        [&min](const auto& v)
        {
            min = std::min(*min_element(v.begin(), v.end()), min);
        }
    );
    return min;
}
