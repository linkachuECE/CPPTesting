class Ball {
    double m_radius{};
    std::string m_color{};

public:
    Ball(double radius = 10.0, std::string color = "black");
    void print() const;
    Ball& timesRadius(int mult);
    Ball& halfRadius();

};