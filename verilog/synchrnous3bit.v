// 3-bit synchronous counter using JK flip-flops
module sync_counter_3bit(
    input clk,
    input rst,
    output [2:0] count
);

    reg [2:0] count_reg;
    wire [2:0] j, k;

    // J-K inputs for each flip-flop
    assign j[0] = 1'b1;
    assign k[0] = 1'b1;
    assign j[1] = count_reg[0];
    assign k[1] = count_reg[0];
    assign j[2] = count_reg[1] & count_reg[0];
    assign k[2] = count_reg[1] & count_reg[0];

    // Counter logic
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            count_reg <= 3'b000;
        end else begin
            count_reg[0] <= (j[0] & ~count_reg[0]) | (~k[0] & count_reg[0]);
            count_reg[1] <= (j[1] & ~count_reg[1]) | (~k[1] & count_reg[1]);
            count_reg[2] <= (j[2] & ~count_reg[2]) | (~k[2] & count_reg[2]);
        end
    end

    assign count = count_reg;

endmodule

// Testbench
module sync_counter_3bit_tb;
    reg clk;
    reg rst;
    wire [2:0] count;

    // Instantiate the counter
    sync_counter_3bit uut (
        .clk(clk),
        .rst(rst),
        .count(count)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Test stimulus
    initial begin
        // Initialize
        rst = 1;
        #10;
        rst = 0;
        
        // Wait for counter to cycle through all values
      #100;
        
        // Reset again
        rst = 1;
        #10;
        rst = 0;
        #50;
        
        $finish;
    end
    // Add waveform dumping
    initial begin
        $dumpfile("sync_counter_3bit.vcd");
        $dumpvars(0, sync_counter_3bit_tb);
    end
    // Monitor changes
    initial begin
        $monitor("Time=%0d rst=%b count=%b", $time, rst, count);
    end

endmodule