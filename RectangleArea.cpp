class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width = min(C, G) - max(A, E);
        int height = min(D, H) - max(B, F);
        width = max(width, 0);
        height = max(height, 0);
        return (C - A) * (D - B) + (G - E) * (H - F) - width * height;
    }
};