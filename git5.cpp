int maxelement(vector<vector<int>> matrix){
    int max = std::numeric_limits<int>::min();

    for_each(matrix.begin(), matrix.end(),
        [&max](const auto& v)
        {
           max = std::max(*max_element(v.begin(), v.end()), max);
        }
    );
    return max;
}