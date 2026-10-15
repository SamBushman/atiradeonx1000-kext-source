# Performance: stock vs candidate

| metric | stock median (us) | cand median (us) | ratio | stock noise | margin | runs s/c | verdict |
|---|---:|---:|---:|---:|---:|---|---|
| 2d.get_config.sel1 | 3.51 | 3.54 | 1.009 | 3.4 % | 10.3 % | 5/5 | OK |
| 2d.get_surface_info.sel2 | 3.75 | 3.72 | 0.992 | 3.2 % | 9.6 % | 5/5 | OK |
| 2d.read_regs_1.sel16 | 4.32 | 4.29 | 0.993 | 3.5 % | 10.4 % | 5/5 | OK |
| 2d.read_regs_2.sel16 | 4.77 | 4.74 | 0.994 | 3.1 % | 9.4 % | 5/5 | OK |
| dvd.check_stamps.sel20 | 3.51 | 3.48 | 0.991 | 3.4 % | 10.3 % | 5/5 | OK |
| dvd.get_config.sel1 | 3.48 | 3.48 | 1.000 | 2.6 % | 7.8 % | 5/5 | OK |
| dvd.get_status.sel2 | 3.48 | 3.45 | 0.991 | 2.6 % | 7.8 % | 5/5 | OK |
| dvd.read_regs.sel13 | 4.29 | 4.29 | 1.000 | 1.4 % | 5.0 % | 5/5 | OK |
| gl.get_config.sel3 | 3.72 | 3.69 | 0.992 | 1.6 % | 5.0 % | 5/5 | OK |
| gl.get_hw_info.sel20 | 3.63 | 3.60 | 0.992 | 3.3 % | 9.9 % | 5/5 | OK |
| gl.get_status.sel4 | 3.69 | 3.63 | 0.984 | 1.6 % | 5.0 % | 5/5 | OK |
| glcycle.ChoosePixelFormat | 33.00 | 33.00 | 1.000 | 0.0 % | 5.0 % | 5/5 | OK |
| glcycle.Clear+Flush | 190.00 | 191.00 | 1.005 | 0.5 % | 5.0 % | 5/5 | OK |
| glcycle.CreateContext | 1967.00 | 1973.00 | 1.003 | 1.7 % | 5.2 % | 5/5 | OK |
| glcycle.Draw100Tri+Flush | 186.00 | 187.00 | 1.005 | 1.1 % | 5.0 % | 5/5 | OK |
| glcycle.ReadPixels | 1491.00 | 1488.00 | 0.998 | 5.9 % | 17.7 % | 5/5 | OK |
| glcycle.SetPBuffer | 1931.00 | 1928.00 | 0.998 | 1.7 % | 5.1 % | 5/5 | OK |
| glcycle.Teardown | 973.00 | 982.00 | 1.009 | 1.7 % | 5.2 % | 5/5 | OK |
| open_close.2d | 98.44 | 98.65 | 1.002 | 0.7 % | 5.0 % | 5/5 | OK |
| open_close.dvd | 159.73 | 159.73 | 1.000 | 0.8 % | 5.0 % | 5/5 | OK |
| open_close.gl | 291.11 | 292.16 | 1.004 | 1.2 % | 5.0 % | 5/5 | OK |
| open_close.surface | 62.01 | 61.86 | 0.998 | 0.5 % | 5.0 % | 5/5 | OK |
| surface.get_state.sel2 | 3.54 | 3.54 | 1.000 | 4.2 % | 12.7 % | 5/5 | OK |
| surface.query_lock.sel11 | 3.60 | 3.63 | 1.008 | 5.0 % | 15.0 % | 5/5 | OK |

Totals: OK 24
