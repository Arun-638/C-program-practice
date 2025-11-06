module full_adder(
    input a, b, cin,
    output sum, cout
);
    
    assign sum = a ^ b ^ cin;
    assign cout = (a & b) | (cin & (a ^ b));
    
endmodule

module full_adder_tb;
    reg a, b, cin;
    wire sum, cout;
    
    full_adder uut(
        .a(a),
        .b(b),
        .cin(cin),
        .sum(sum),
        .cout(cout)
    );
    
    initial begin
        // Test all possible input combinations
        a = 0; b = 0; cin = 0; #10;
        a = 0; b = 0; cin = 1; #10;
        a = 0; b = 1; cin = 0; #10;
        a = 0; b = 1; cin = 1; #10;
        a = 1; b = 0; cin = 0; #10;
        a = 1; b = 0; cin = 1; #10;
        a = 1; b = 1; cin = 0; #10;
        a = 1; b = 1; cin = 1; #10;
        
        $finish;
    end
    
    initial begin
        $dumpfile("full_adder.vcd");
        $dumpvars(0,full_adder_tb);
        $monitor("Time=%0t a=%b b=%b cin=%b sum=%b cout=%b", 
        $time, a, b, cin, sum, cout);
    end
    
endmodule