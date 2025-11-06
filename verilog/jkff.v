// JK Flip-flop module
module jkff(
    input j, k, clk, rst,
    output reg q
);
    
    always @(posedge clk or posedge rst) begin
        if (rst)
            q <= 1'b0;
        else begin
            case ({j,k})
                2'b00: q <= q;      // No change
                2'b01: q <= 1'b0;   // Reset
                2'b10: q <= 1'b1;   // Set
                2'b11: q <= ~q;     // Toggle
            endcase
        end
    end
endmodule

// Testbench
module jkff_tb;
    reg j, k, clk, rst;
    wire q;
    
    // Instantiate JK flip-flop
    jkff uut(
        .j(j),
        .k(k),
        .clk(clk),
        .rst(rst),
        .q(q)
    );
    
    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    
    // Test stimulus
    initial begin
        // Create dump file
        $dumpfile("jkff_tb.vcd");
        $dumpvars(0, jkff_tb);
        
        // Initialize inputs
        j = 0; k = 0; rst = 1;
        #10 rst = 0;
        
        // Test cases
        #10 j = 0; k = 0;  // No change
        #10 j = 0; k = 1;  // Reset
        #10 j = 1; k = 0;  // Set
        #10 j = 1; k = 1;  // Toggle
        #10 j = 1; k = 1;  // Toggle
        #10 j = 0; k = 0;  // No change
        
        #10 $finish;
    end
    initial
        $monitor("Time=%0d rst=%b j=%b k=%b q=%b", $time, rst, j, k, q);
endmodule