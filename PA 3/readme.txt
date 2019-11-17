CSCI 103 Image Filtering Programming Assignment 

Name: Justin Kuo

Email Address: kuojusti@usc.edu

Answer the questions posed in the writeup below.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

: none

================================ Questions ==================================

1. Padding design: If we restrict the size of the Gaussian kernels to odd 
integers between 3 and 11 inclusive, and we only allow 256x256 pixel images, 
what is the size of the largest padded image needed to handle padding with 
any kernel size? At what index will the upper-left pixel of the original 
image be placed in the padded image (answer in terms of N, the kernel size)? 
At what index in the padded array will the lower-right pixel of the original 
image be placed?

:If the size of the Gaussian kernels were restricted between size 3 and 11,
then the largest padded image size would be 266x266. The upper left pixel 
of the original image would be at [N/2][N/2]. The lower right pixel of the 
original image would be at [(N/2) + 255][(N/2) + 255].

2. Kernel Design: Manually compute the raw and normalized Gaussian kernels 
for N=3, sigma=2. Use 4 decimal places. Discuss what would happen to the 
image if we used the raw kernel values.

: Raw kernel:  0.7788 0.8825 0.7788
               0.8825    1   0.8825
               0.7788 0.8825 0.7788
 sum = 7.6452
 
 Normalized kernel: 0.1019 0.1154 0.1019
                    0.1154 0.1308 0.1154
                    0.1019 0.1154 0.1019
 If we used the raw kernel values, 
then the image would be brighter 
than the orignal.

3. Experimenation:  Provide the results for ALL experiments listed in the
                    writeup.

: When I increased both N and sigma, the blur effect became stronger.
If I held N constant and varied sigma, 
The sobel filter highlights the edges that are of similar color,
but blackens most of image if the picture is made up of 
that one color.

4. Express in mathematical terms how the number of calculations your 
 program performs grows with the size, N, of the kernel.

:  The number of calculations the program performs grows by N^2, 
because the size of the kernel is NxN.


================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:

Do you have any other remarks?

:
