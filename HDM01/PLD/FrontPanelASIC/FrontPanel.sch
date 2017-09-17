<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="xc9500xl" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="XLXN_2" />
        <signal name="PHA" />
        <signal name="PHB" />
        <signal name="ECLK" />
        <signal name="IRQ" />
        <signal name="DIR" />
        <signal name="XLXN_15" />
        <signal name="CLK_50" />
        <signal name="XLXN_24" />
        <signal name="LED_0" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="LED_1" />
        <signal name="LED_2" />
        <signal name="XLXN_41" />
        <signal name="MOSI" />
        <signal name="SCLK" />
        <signal name="LED(7:0)" />
        <signal name="LED(0)" />
        <signal name="LED(1)" />
        <signal name="LED(2)" />
        <signal name="RESET" />
        <signal name="BYTE_IN" />
        <signal name="XLXN_78(7:0)" />
        <signal name="XLXN_81" />
        <signal name="XLXN_83" />
        <signal name="MISO" />
        <signal name="XLXN_85" />
        <signal name="SS" />
        <signal name="XLXN_89" />
        <port polarity="Input" name="PHA" />
        <port polarity="Input" name="PHB" />
        <port polarity="Input" name="ECLK" />
        <port polarity="Output" name="IRQ" />
        <port polarity="Output" name="DIR" />
        <port polarity="Output" name="CLK_50" />
        <port polarity="Output" name="LED_0" />
        <port polarity="Output" name="LED_1" />
        <port polarity="Output" name="LED_2" />
        <port polarity="Input" name="MOSI" />
        <port polarity="Input" name="SCLK" />
        <port polarity="Input" name="RESET" />
        <port polarity="Output" name="BYTE_IN" />
        <port polarity="Output" name="MISO" />
        <port polarity="Input" name="SS" />
        <blockdef name="rotary_decoder">
            <timestamp>2017-8-1T20:24:40</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="ibuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
        </blockdef>
        <blockdef name="obuf">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="0" y2="-64" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
        </blockdef>
        <blockdef name="clock_divider">
            <timestamp>2017-8-9T18:54:53</timestamp>
            <rect width="256" x="64" y="-64" height="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="spi">
            <timestamp>2017-8-24T16:49:39</timestamp>
            <rect width="64" x="0" y="404" height="24" />
            <line x2="0" y1="416" y2="416" x1="64" />
            <line x2="384" y1="352" y2="352" x1="320" />
            <line x2="0" y1="288" y2="288" x1="64" />
            <line x2="384" y1="224" y2="224" x1="320" />
            <rect width="64" x="320" y="148" height="24" />
            <line x2="384" y1="160" y2="160" x1="320" />
            <line x2="0" y1="32" y2="32" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="256" x="64" y="-128" height="704" />
        </blockdef>
        <blockdef name="counter8">
            <timestamp>2017-8-24T17:4:49</timestamp>
            <rect width="64" x="320" y="20" height="24" />
            <line x2="384" y1="32" y2="32" x1="320" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="256" x="64" y="-192" height="256" />
        </blockdef>
        <blockdef name="obuft">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-96" y2="-96" x1="0" />
            <line x2="64" y1="-96" y2="-96" x1="96" />
            <line x2="96" y1="-48" y2="-96" x1="96" />
            <line x2="128" y1="-32" y2="-32" x1="224" />
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="64" y1="-64" y2="0" x1="64" />
            <line x2="64" y1="-32" y2="-64" x1="128" />
            <line x2="128" y1="0" y2="-32" x1="64" />
        </blockdef>
        <block symbolname="rotary_decoder" name="XLXI_2">
            <blockpin signalname="XLXN_1" name="rotary_a" />
            <blockpin signalname="XLXN_2" name="rotary_b" />
            <blockpin signalname="XLXN_15" name="clk" />
            <blockpin signalname="XLXN_81" name="detent" />
            <blockpin signalname="XLXN_83" name="dir" />
        </block>
        <block symbolname="ibuf" name="XLXI_3">
            <blockpin signalname="PHA" name="I" />
            <blockpin signalname="XLXN_1" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_4">
            <blockpin signalname="PHB" name="I" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="ibuf" name="XLXI_5">
            <blockpin signalname="ECLK" name="I" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_7">
            <blockpin signalname="XLXN_83" name="I" />
            <blockpin signalname="DIR" name="O" />
        </block>
        <block symbolname="clock_divider" name="XLXI_15">
            <attr value="LOW" name="PWR_MODE">
                <trait verilog="all:0 wsynth:1" />
                <trait vhdl="all:0 wa:1 wd:1" />
            </attr>
            <blockpin signalname="XLXN_15" name="clk" />
            <blockpin signalname="XLXN_41" name="clk_out" />
        </block>
        <block symbolname="obuf" name="XLXI_16">
            <blockpin signalname="XLXN_41" name="I" />
            <blockpin signalname="CLK_50" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_18">
            <blockpin signalname="LED(0)" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="XLXN_24" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_19">
            <blockpin signalname="XLXN_24" name="I" />
            <blockpin signalname="LED_0" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_20">
            <blockpin signalname="LED(1)" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="XLXN_27" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_21">
            <blockpin signalname="LED(2)" name="I0" />
            <blockpin signalname="XLXN_41" name="I1" />
            <blockpin signalname="XLXN_28" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_27">
            <blockpin signalname="XLXN_27" name="I" />
            <blockpin signalname="LED_1" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_28">
            <blockpin signalname="XLXN_28" name="I" />
            <blockpin signalname="LED_2" name="O" />
        </block>
        <block symbolname="obuf" name="XLXI_6">
            <blockpin signalname="XLXN_81" name="I" />
            <blockpin signalname="IRQ" name="O" />
        </block>
        <block symbolname="spi" name="XLXI_30">
            <attr value="LOW" name="PWR_MODE">
                <trait verilog="all:0 wsynth:1" />
                <trait vhdl="all:0 wa:1 wd:1" />
            </attr>
            <blockpin signalname="SCLK" name="SCLK" />
            <blockpin signalname="MOSI" name="MOSI" />
            <blockpin signalname="SS" name="SS" />
            <blockpin signalname="RESET" name="NRST" />
            <blockpin signalname="XLXN_85" name="MISO" />
            <blockpin signalname="BYTE_IN" name="BYTE_IN" />
            <blockpin signalname="LED(7:0)" name="LEDPORT(7:0)" />
            <blockpin signalname="XLXN_78(7:0)" name="INPUTPORT(7:0)" />
        </block>
        <block symbolname="counter8" name="XLXI_31">
            <attr value="LOW" name="PWR_MODE">
                <trait verilog="all:0 wsynth:1" />
                <trait vhdl="all:0 wa:1 wd:1" />
            </attr>
            <blockpin signalname="XLXN_81" name="CLK" />
            <blockpin signalname="RESET" name="RST" />
            <blockpin signalname="XLXN_83" name="DIR" />
            <blockpin signalname="XLXN_78(7:0)" name="COUNT(7:0)" />
        </block>
        <block symbolname="obuft" name="XLXI_32">
            <blockpin signalname="XLXN_85" name="I" />
            <blockpin signalname="SS" name="T" />
            <blockpin signalname="MISO" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="624" y="480" name="XLXI_2" orien="R0">
        </instance>
        <branch name="XLXN_1">
            <wire x2="624" y1="320" y2="320" x1="592" />
        </branch>
        <instance x="368" y="352" name="XLXI_3" orien="R0" />
        <branch name="XLXN_2">
            <wire x2="624" y1="384" y2="384" x1="592" />
        </branch>
        <instance x="368" y="416" name="XLXI_4" orien="R0" />
        <instance x="368" y="480" name="XLXI_5" orien="R0" />
        <branch name="PHA">
            <wire x2="368" y1="320" y2="320" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="320" name="PHA" orien="R180" />
        <branch name="PHB">
            <wire x2="368" y1="384" y2="384" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="384" name="PHB" orien="R180" />
        <branch name="ECLK">
            <wire x2="368" y1="448" y2="448" x1="336" />
        </branch>
        <iomarker fontsize="28" x="336" y="448" name="ECLK" orien="R180" />
        <branch name="IRQ">
            <wire x2="1296" y1="320" y2="320" x1="1264" />
        </branch>
        <iomarker fontsize="28" x="1296" y="320" name="IRQ" orien="R0" />
        <branch name="DIR">
            <wire x2="1296" y1="448" y2="448" x1="1264" />
        </branch>
        <iomarker fontsize="28" x="1296" y="448" name="DIR" orien="R0" />
        <instance x="1472" y="848" name="XLXI_16" orien="R0" />
        <branch name="CLK_50">
            <wire x2="1728" y1="816" y2="816" x1="1696" />
        </branch>
        <iomarker fontsize="28" x="1728" y="816" name="CLK_50" orien="R0" />
        <instance x="1888" y="1200" name="XLXI_18" orien="R0" />
        <branch name="XLXN_24">
            <wire x2="2176" y1="1104" y2="1104" x1="2144" />
        </branch>
        <instance x="2176" y="1136" name="XLXI_19" orien="R0" />
        <branch name="LED_0">
            <wire x2="2432" y1="1104" y2="1104" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1104" name="LED_0" orien="R0" />
        <instance x="1888" y="1344" name="XLXI_20" orien="R0" />
        <instance x="1888" y="1488" name="XLXI_21" orien="R0" />
        <branch name="XLXN_27">
            <wire x2="2176" y1="1248" y2="1248" x1="2144" />
        </branch>
        <instance x="2176" y="1280" name="XLXI_27" orien="R0" />
        <branch name="XLXN_28">
            <wire x2="2176" y1="1392" y2="1392" x1="2144" />
        </branch>
        <instance x="2176" y="1424" name="XLXI_28" orien="R0" />
        <branch name="LED_1">
            <wire x2="2432" y1="1248" y2="1248" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1248" name="LED_1" orien="R0" />
        <branch name="LED_2">
            <wire x2="2432" y1="1392" y2="1392" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1392" name="LED_2" orien="R0" />
        <branch name="MOSI">
            <wire x2="448" y1="1248" y2="1248" x1="416" />
        </branch>
        <branch name="SCLK">
            <wire x2="448" y1="1184" y2="1184" x1="416" />
        </branch>
        <iomarker fontsize="28" x="416" y="1184" name="SCLK" orien="R180" />
        <iomarker fontsize="28" x="416" y="1248" name="MOSI" orien="R180" />
        <instance x="1040" y="352" name="XLXI_6" orien="R0" />
        <instance x="1040" y="480" name="XLXI_7" orien="R0" />
        <branch name="LED(7:0)">
            <wire x2="1072" y1="1440" y2="1440" x1="832" />
            <wire x2="1072" y1="1440" y2="1744" x1="1072" />
            <wire x2="1344" y1="1744" y2="1744" x1="1072" />
            <wire x2="1344" y1="1104" y2="1168" x1="1344" />
            <wire x2="1344" y1="1168" y2="1264" x1="1344" />
            <wire x2="1344" y1="1264" y2="1344" x1="1344" />
            <wire x2="1344" y1="1344" y2="1744" x1="1344" />
        </branch>
        <bustap x2="1440" y1="1168" y2="1168" x1="1344" />
        <bustap x2="1440" y1="1264" y2="1264" x1="1344" />
        <bustap x2="1440" y1="1344" y2="1344" x1="1344" />
        <branch name="LED(0)">
            <wire x2="1664" y1="1168" y2="1168" x1="1440" />
            <wire x2="1664" y1="1136" y2="1168" x1="1664" />
            <wire x2="1888" y1="1136" y2="1136" x1="1664" />
        </branch>
        <branch name="LED(1)">
            <wire x2="1664" y1="1264" y2="1264" x1="1440" />
            <wire x2="1664" y1="1264" y2="1280" x1="1664" />
            <wire x2="1888" y1="1280" y2="1280" x1="1664" />
        </branch>
        <branch name="LED(2)">
            <wire x2="1664" y1="1344" y2="1344" x1="1440" />
            <wire x2="1664" y1="1344" y2="1424" x1="1664" />
            <wire x2="1888" y1="1424" y2="1424" x1="1664" />
        </branch>
        <branch name="RESET">
            <wire x2="112" y1="96" y2="1408" x1="112" />
            <wire x2="336" y1="1408" y2="1408" x1="112" />
            <wire x2="336" y1="1408" y2="1568" x1="336" />
            <wire x2="448" y1="1568" y2="1568" x1="336" />
            <wire x2="1488" y1="96" y2="96" x1="112" />
            <wire x2="1488" y1="96" y2="416" x1="1488" />
            <wire x2="1536" y1="416" y2="416" x1="1488" />
            <wire x2="336" y1="1568" y2="1568" x1="272" />
        </branch>
        <iomarker fontsize="28" x="272" y="1568" name="RESET" orien="R180" />
        <branch name="BYTE_IN">
            <wire x2="864" y1="1632" y2="1632" x1="832" />
        </branch>
        <iomarker fontsize="28" x="864" y="1632" name="BYTE_IN" orien="R0" />
        <instance x="448" y="1280" name="XLXI_30" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="PWR_MODE" x="192" y="164" type="instance" />
        </instance>
        <instance x="1536" y="512" name="XLXI_31" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="PWR_MODE" x="192" y="-124" type="instance" />
        </instance>
        <branch name="XLXN_78(7:0)">
            <wire x2="448" y1="1696" y2="1696" x1="320" />
            <wire x2="320" y1="1696" y2="2096" x1="320" />
            <wire x2="2832" y1="2096" y2="2096" x1="320" />
            <wire x2="2816" y1="544" y2="544" x1="1920" />
            <wire x2="2816" y1="544" y2="560" x1="2816" />
            <wire x2="2832" y1="560" y2="560" x1="2816" />
            <wire x2="2832" y1="560" y2="2096" x1="2832" />
        </branch>
        <branch name="XLXN_81">
            <wire x2="1024" y1="320" y2="320" x1="1008" />
            <wire x2="1040" y1="320" y2="320" x1="1024" />
            <wire x2="1024" y1="208" y2="320" x1="1024" />
            <wire x2="1520" y1="208" y2="208" x1="1024" />
            <wire x2="1520" y1="208" y2="352" x1="1520" />
            <wire x2="1536" y1="352" y2="352" x1="1520" />
        </branch>
        <branch name="XLXN_83">
            <wire x2="1024" y1="448" y2="448" x1="1008" />
            <wire x2="1040" y1="448" y2="448" x1="1024" />
            <wire x2="1024" y1="448" y2="560" x1="1024" />
            <wire x2="1456" y1="560" y2="560" x1="1024" />
            <wire x2="1456" y1="480" y2="560" x1="1456" />
            <wire x2="1536" y1="480" y2="480" x1="1456" />
        </branch>
        <text style="fontsize:24;fontname:Arial" x="144" y="520">CLOCK: 500Hz from ARM Cortex SysTick</text>
        <branch name="XLXN_41">
            <wire x2="1312" y1="816" y2="816" x1="1104" />
            <wire x2="1472" y1="816" y2="816" x1="1312" />
            <wire x2="1312" y1="816" y2="1072" x1="1312" />
            <wire x2="1696" y1="1072" y2="1072" x1="1312" />
            <wire x2="1888" y1="1072" y2="1072" x1="1696" />
            <wire x2="1696" y1="1072" y2="1216" x1="1696" />
            <wire x2="1888" y1="1216" y2="1216" x1="1696" />
            <wire x2="1696" y1="1216" y2="1360" x1="1696" />
            <wire x2="1888" y1="1360" y2="1360" x1="1696" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="608" y1="448" y2="448" x1="592" />
            <wire x2="624" y1="448" y2="448" x1="608" />
            <wire x2="608" y1="448" y2="816" x1="608" />
            <wire x2="720" y1="816" y2="816" x1="608" />
        </branch>
        <instance x="720" y="848" name="XLXI_15" orien="R0">
            <attrtext style="fontsize:28;fontname:Arial;displayformat:NAMEEQUALSVALUE" attrname="PWR_MODE" x="192" y="-92" type="instance" />
        </instance>
        <instance x="928" y="1360" name="XLXI_32" orien="R0" />
        <branch name="MISO">
            <wire x2="1184" y1="1328" y2="1328" x1="1152" />
        </branch>
        <iomarker fontsize="28" x="1184" y="1328" name="MISO" orien="R0" />
        <branch name="XLXN_85">
            <wire x2="880" y1="1504" y2="1504" x1="832" />
            <wire x2="880" y1="1328" y2="1504" x1="880" />
            <wire x2="928" y1="1328" y2="1328" x1="880" />
        </branch>
        <branch name="SS">
            <wire x2="256" y1="1024" y2="1312" x1="256" />
            <wire x2="448" y1="1312" y2="1312" x1="256" />
            <wire x2="448" y1="1024" y2="1024" x1="256" />
            <wire x2="832" y1="1024" y2="1024" x1="448" />
            <wire x2="928" y1="1024" y2="1024" x1="832" />
            <wire x2="928" y1="1024" y2="1264" x1="928" />
            <wire x2="448" y1="944" y2="944" x1="352" />
            <wire x2="448" y1="944" y2="1024" x1="448" />
        </branch>
        <iomarker fontsize="28" x="352" y="944" name="SS" orien="R180" />
    </sheet>
</drawing>