# Performance: stock vs candidate

| metric | stock median (us) | cand median (us) | ratio | stock noise | margin | runs s/c | verdict |
|---|---:|---:|---:|---:|---:|---|---|
| 2d.get_config.sel1 | 3.51 | 3.54 | 1.009 | 1.7 % | 5.1 % | 5/5 | OK |
| 2d.get_surface_info.sel2 | 3.72 | 3.81 | 1.024 | 2.4 % | 7.3 % | 5/5 | OK |
| 2d.read_regs_1.sel16 | 4.32 | 4.35 | 1.007 | 2.1 % | 6.2 % | 5/5 | OK |
| 2d.read_regs_2.sel16 | 4.77 | 4.83 | 1.013 | 2.5 % | 7.5 % | 5/5 | OK |
| dvd.check_stamps.sel20 | 3.51 | 3.57 | 1.017 | 1.7 % | 5.1 % | 5/5 | OK |
| dvd.get_config.sel1 | 3.48 | 3.54 | 1.017 | 2.6 % | 7.8 % | 5/5 | OK |
| dvd.get_status.sel2 | 3.48 | 3.57 | 1.026 | 2.6 % | 7.8 % | 5/5 | OK |
| dvd.read_regs.sel13 | 4.29 | 4.35 | 1.014 | 2.1 % | 6.3 % | 5/5 | OK |
| gl.get_config.sel3 | 3.75 | 3.75 | 1.000 | 3.2 % | 9.6 % | 5/5 | OK |
| gl.get_hw_info.sel20 | 3.63 | 3.66 | 1.008 | 2.5 % | 7.4 % | 5/5 | OK |
| gl.get_status.sel4 | 3.63 | 3.66 | 1.008 | 3.3 % | 9.9 % | 5/5 | OK |
| glcycle.ChoosePixelFormat | 33.00 | 33.00 | 1.000 | 0.0 % | 5.0 % | 5/5 | OK |
| glcycle.Clear+Flush | 202.00 | 196.00 | 0.970 | 0.5 % | 5.0 % | 5/5 | OK |
| glcycle.CreateContext | 1951.00 | 1956.00 | 1.003 | 1.0 % | 5.0 % | 5/5 | OK |
| glcycle.Draw100Tri+Flush | 121.00 | 120.00 | 0.992 | 0.8 % | 5.0 % | 5/5 | OK |
| glcycle.ReadPixels | 1523.00 | 1510.00 | 0.991 | 1.2 % | 5.0 % | 5/5 | OK |
| glcycle.SetPBuffer | 1886.00 | 1893.00 | 1.004 | 0.8 % | 5.0 % | 5/5 | OK |
| glcycle.Teardown | 895.00 | 887.00 | 0.991 | 1.9 % | 5.7 % | 5/5 | OK |
| open_close.2d | 86.08 | 87.04 | 1.011 | 1.0 % | 5.0 % | 5/5 | OK |
| open_close.dvd | 150.04 | 157.24 | 1.048 | 0.9 % | 5.0 % | 5/5 | OK |
| open_close.gl | 279.53 | 283.79 | 1.015 | 1.5 % | 5.0 % | 5/5 | OK |
| open_close.surface | 60.84 | 59.91 | 0.985 | 0.9 % | 5.0 % | 5/5 | OK |
| surface.get_state.sel2 | 3.54 | 3.60 | 1.017 | 1.7 % | 5.1 % | 5/5 | OK |
| surface.query_lock.sel11 | 3.60 | 3.66 | 1.017 | 3.3 % | 10.0 % | 5/5 | OK |

Totals: OK 24
